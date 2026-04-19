#include <stdlib.h>
#include "htab_private.h"

void htab_clear(htab_t * t){
    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t* current = t->ptr[i];
        while(current != NULL){
            htab_item_t* next = current->next;
            free((char*)current->pair.key);
            free(current);
            current = next;
        }
        t->ptr[i] = NULL;
    }
    t->size= 0;
}