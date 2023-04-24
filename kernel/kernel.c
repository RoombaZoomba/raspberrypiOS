#include <stddef.h>
#include <stdint.h>
#include "ouruart.h"
#include "ourstdio.h"
#include "ourstdlib.h"
#include "spinlock.h"

//uart_init();
//uint32_t r0, uint32_t r1, uint32_t atags
//    (void) r0;
//    (void) r1;
//    (void) atags;
//char buf[256];
void kernel_main()
{

    //spinlock_t my_spinlock;
    //spinlock_lock(&my_spinlock);
    puts("Hello, World!\n\0");
    //spinlock_unlock(&my_spinlock);
}
