#include <string.h>
#include <stdlib.h>
#include "htab_struct.h"


htab_t * htab_init(size_t n){
    htab_t* t = malloc(sizeof(htab_t) + n * sizeof(htab_item_t*));
    if(t == NULL) return NULL;

    t->size = 0;
    t->arr_size = n;

    for(size_t i = 0; i < n; i++){
        t->ptr[i] = NULL;
    }

    return t;
}