#include <string.h>
#include "htab_private.h"

htab_pair_t * htab_find(const htab_t * t, htab_key_t key){
    size_t idx = htab_hash_function(key) % t->arr_size;
    
    for(htab_item_t *current = t->ptr[idx]; current != NULL; current = current->next){
        if (strcmp(current->pair.key, key) == 0){
            return &current->pair;
        }        
    }

    return NULL;
}