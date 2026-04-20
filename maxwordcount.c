/*
primes.c
Riešenie IJC-DU1, príklad a), 25.3.2026
Autor: Julius Kundrat FIT
Preložené: gcc 13.3
Reads words from stdin into a hash table, tracking their frequency.
Prints the most frequent words and their occurrence count.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "io.c"
#include "htab.h" 

#define MAX_WORD_LEN 100

unsigned max = 0;

void find_max(htab_pair_t* p){
    if(p->value > max){
        max = p->value;
    }
}

void print_max(htab_pair_t* p){
    if(p->value == max){
        printf("%s \t %d\n", p->key, p->value);
    }
}


int main(int argc, char* argv[]){

    FILE* input = stdin;
    if(argc == 2){
        input = fopen(argv[1], "r");
    }

    htab_t* t = htab_init(5);

    char word[MAX_WORD_LEN];

    while (read_word(MAX_WORD_LEN, word, input) != EOF) {
        htab_pair_t *p = htab_lookup_add(t, word);
        if(!p){
            fprintf(stderr, "Memory allocation error");
            return 1;
        }
    }

    htab_for_each(t, find_max);
    htab_for_each(t, print_max);

    htab_free(t);

    return 0;
}