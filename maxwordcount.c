#include <stdio.h>
#include <string.h>
#include "htab.h" 

#define MAX_WORD_LEN 100

int main(char* args[], int argv){

    FILE* input = stdin;
    if(argv == 2){
        input = fopen(args[1], "r");
    }

    htab_t* t = htab_init(5);

    char word[MAX_WORD_LEN];
    while (read_word(MAX_WORD_LEN, word, stdin) != EOF) {
    // každé volanie prečíta ďalšie slovo
        htab_pair_t *p = htab_lookup_add(t, word);
        p->value++;
    }


    htab_free(t);

    return 0;
}