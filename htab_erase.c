#include "htab_private.h"
#include <stdlib.h>
#include <string.h>

bool htab_erase(htab_t *t, htab_key_t key) {
    size_t idx = htab_hash_function(key) % t->arr_size;
    htab_item_t** prev = &t->ptr[idx];
    for(htab_item_t *current = t->ptr[idx]; current != NULL; current = current->next){
        if(strcmp(current->pair.key, key) == 0){
            *prev = current->next;
            free((char*)current->pair.key);
            free(current);
            t->size--;
            return true;
        }
        prev = &current->next;
    }
    return false;
}