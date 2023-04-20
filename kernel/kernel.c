#include <stddef.h>
#include <stdint.h>
#include "ouruart.h"
#include "ourstdio.h"
#include "ourstdlib.h"

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
    char buf[256];
    // Declare as unused
    (void) r0;
    (void) r1;
    (void) atags;

    uart_init();
    puts("Hello, kernel World!\n");
    while (1) {
        gets(buf,256);
        puts(buf);
        putc('\n');
    }
}