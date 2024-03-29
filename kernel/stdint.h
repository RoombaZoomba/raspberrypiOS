#ifndef _STDINT_H_
#define _STDINT_H_

// a class that will be used primarily in heap.cc

typedef unsigned char uint8_t;
typedef char int8_t;

typedef unsigned short uint16_t;
typedef short int16_t;

typedef unsigned long uint32_t;
typedef long int32_t;

typedef unsigned long uintptr_t;
typedef long intptr_t;

typedef unsigned long ureg_t;
typedef long reg_t;

typedef unsigned int size_t;
typedef int ssize_t;

typedef unsigned long long uint64_t;

typedef long long int64_t;

#endif