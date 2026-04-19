#include <stdlib.h>
#include <stdio.h>
#include "htab_private.h"

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key){
    size_t idx = htab_hash_function(key) % t->arr_size;

    // increment value if key found in table
    for(htab_item_t *current = t->ptr[idx]; current != NULL; current = current->next){
        if (strcmp(current->pair.key, key) == 0){
            current->pair.value++;
            printf("%s found, value set to %d\n", key, current->pair.value);
            return &current->pair;
        }
    }

    // add new item if key not found in table
    htab_item_t* new = malloc(sizeof(htab_item_t));
    if(!new) return NULL;

    char* str = malloc(strlen(key) + 1);
    if (!str) {
        free(new);
        return NULL;
    }
    strcpy(str, key);
    new->pair.key = str;
    new->pair.value = 1;
    new->next = t->ptr[idx];
    t->ptr[idx] = new;
    t->size++;
    printf("%s not found, added %s to hashtable\n", key, key);
    
    return &new->pair;
}