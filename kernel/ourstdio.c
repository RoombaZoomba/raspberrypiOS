#include "ouruart.h"
#include "ourstdio.h"
#include "ourstdlib.h"

// this class is more or less similar to Dr. Gheith's io.h class with expanded functions

// gets a char/byte, this is like outb or U8250::get
char getc(void) {
    return uart_getc();
}

// puts a char/byte, this is like inb or U8250::put
void putc(char c) {
    uart_putc(c);
}

// like outl in gheithOS
void gets(char *buf, int len) {
    char c;
    int i;
    // Leave a spot for null char in buffer
    for (i = 0; (c = getc() != '\r') && len > 1; i++, len--) {
        putc(c);
        buf[i] = c;
    }

    putc('\n'); 

    // null terminator
    if (c == '\n') 
        buf[i] = '\0';
    else
        buf[len-1] = '\0';
}

// like inl in gheithOS
void puts(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        putc(str[i]);
        i++;
    }
}
