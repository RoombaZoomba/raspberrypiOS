#include "ourstdlib.h"

// memcpy but not c standard library's memcpy
void memcpy(void *dest, void *src, int bytes) {
    char *d = dest;
    char *s = src;
    while (bytes) {
        *d = *s;
        *d++;
        *s++;
        bytes--;
    }
}

void bzero(void *dest, int bytes) {
    char *d = dest;
    while (bytes--) {
        *d = 0;
        *d++;
        bytes--;
    }
}

// converts int to a string
// pretty much from geeksforgeeks article and adapted to C
char *itoa(int i) {
    static char buf[12];
    int j = 0;
    int is_neg = 0; // treat as bool

    if (i == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return buf;
    }

    if (i < 0) {
        is_neg = 1;
        i = -i;
    }

    while (i != 0) {
       buf[j++] = '0' + (i % 10); 
       i = i / 10;
    }

    if (is_neg)
        buf[j++] = '-';

    buf[j] = '\0';
    j--;
    
    i = 0;
    while (i < j) {
        is_neg = buf[i];
        buf[i] = buf[j];
        buf[j] = is_neg;
        i++;
        j--;
    }

    return buf;
}
