#ifndef HTAB_STRUCT_H__
#define HTAB_STRUCT_H__

#include "htab.h"

// Položka lineárně zřetězeného seznamu
typedef struct htab_item {
    struct htab_item *next;
    htab_pair_t pair; // Obsahuje key a value
} htab_item_t;

// Definice struktury tabulky (skryto před uživatelem)
struct htab {
    size_t size;             // Aktuální počet záznamů
    size_t arr_size;         // Velikost pole (počet bucketů)
    htab_item_t* ptr[]; // Flexible array member
};

#endif