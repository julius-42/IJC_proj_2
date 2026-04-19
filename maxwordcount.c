#include <stdio.h>
#include <string.h>
#include "htab.h" 

int main(){

    htab_t* t = htab_init(5);
    printf("%ld", htab_size(t));
    htab_free(t);

    return 0;
}