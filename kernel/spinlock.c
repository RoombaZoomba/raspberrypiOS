#include <stdatomic.h>
#include "spinlock.h"

/*
    We are using gcc's atomic operations
    to implement our spinlock
    Worked by Nathan Cheng
*/

void spinlock_init(spinlock_t *lock) {
    atomic_flag_clear(&lock->flag);
}

void spinlock_lock(spinlock_t *lock) {
    while (atomic_flag_test_and_set(&lock->flag));
}

void spinlock_unlock(spinlock_t *lock) {
    atomic_flag_clear(&lock->flag);
}
