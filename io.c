#include <stdio.h>

int read_word(unsigned max, char s[max], FILE *f) {
    int c;

    // skip white spaces
    while ((c = fgetc(f)) != EOF && isspace(c))
        ;

    // return EOF if reached end of the file
    if (c == EOF)
        return EOF;

    // read word and count its length
    unsigned i = 0;
    do {
        if (i < max - 1)
            s[i++] = c;
    } while ((c = fgetc(f)) != EOF && !isspace(c));

    s[i] = '\0';
    return i;
}