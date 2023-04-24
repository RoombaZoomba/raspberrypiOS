#include <stddef.h>
#include <stdint.h>
#include "ouruart.h"
#include "ourstdio.h"
#include "ourstdlib.h"
#include "spinlock.h"

// spin lock test
void testing_spinlock() {
    spinlock_t my_spinlock;
    spinlock_lock(&my_spinlock);
    puts("Hello, World!\n\0");
    spinlock_unlock(&my_spinlock);
}

// atomic operations test
void testing_atomic() {

}

// where our tests can be printed out and stuff, would have expanded to test threads and more.
void kernel_main() {
    uart_init();
    testing_spinlock();
}