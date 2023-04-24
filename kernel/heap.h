#ifndef _HEAP_H_
#define _HEAP_H_

#include "stdint.h"

// UNTESTED 

extern void heapInit(void* start, size_t bytes);

extern void* malloc(size_t size);

extern void free(void* p);

#endif