#include "htab_private.h"

void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data)) {
    for (size_t i = 0; i < t->arr_size; i++)
        for (htab_item_t *current = t->ptr[i]; current != NULL; current = current->next)
            f(&current->pair);
}