#ifndef ATOMIC_H
#define ATOMIC_H

#include <stdint.h>
#include <stdatomic.h>

typedef struct spinlock {
    atomic_flag flag;
} spinlock_t;

void spinlock_init(spinlock_t *lock);
void spinlock_lock(spinlock_t *lock);
void spinlock_unlock(spinlock_t *lock);
#endif /* ATOMIC_H */
