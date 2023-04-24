#include "heap.h"
#include "stdint.h"
#include "atomic.h"

// this is highly untested, we tried to adapt Gheith's heap as best as we can 
// no way to test new and delete since they're not really C functions, would have
// to use standard malloc and free
/* A first-fit heap */

static int *array;
static int len;
static int safe = 0;
static int avail = 0;

void makeTaken(int i, int ints);
void makeAvail(int i, int ints);

int abs(int x) {
    if (x < 0) return -x; else return x;
}

int size(int i) {
    return abs(array[i]);
}

int headerFromFooter(int i) {
    return i - size(i) + 1;
}

int footerFromHeader(int i) {
    return i + size(i) - 1;
}
    
int sanity(int i) {
    if (safe) {
        if (i == 0) return 0;
        if ((i < 0) || (i >= len)) {
            return i;
        }
        int footer = footerFromHeader(i);
        if ((footer < 0) || (footer >= len)) {
            return i;
        }
        int hv = array[i];
        int fv = array[footer];
  
        if (hv != fv) {
            return i;
        }
    }

    return i;
}

int left(int i) {
    return sanity(headerFromFooter(i-1));
}

int right(int i) {
    return sanity(i + size(i));
}

int next(int i) {
    return sanity(array[i+1]);
}

int prev(int i) {
    return sanity(array[i+2]);
}

void setNext(int i, int x) {
    array[i+1] = x;
}

void setPrev(int i, int x) {
    array[i+2] = x;
}

void remove(int i) {
    int prevIndex = prev(i);
    int nextIndex = next(i);

    if (prevIndex == 0) {
        /* at head */
        avail = nextIndex;
    } else {
        /* in the middle */
        setNext(prevIndex,nextIndex);
    }
    if (nextIndex != 0) {
        setPrev(nextIndex,prevIndex);
    }
}

void makeAvail(int i, int ints) {
    array[i] = ints;
    array[footerFromHeader(i)] = ints;    
    setNext(i,avail);
    setPrev(i,0);
    if (avail != 0) {
        setPrev(avail,i);
    }
    avail = i;
}

void makeTaken(int i, int ints) {
    array[i] = -ints;
    array[footerFromHeader(i)] = -ints;    
}

int isAvail(int i) {
    return array[i] > 0;
}

int isTaken(int i) {
    return array[i] < 0;
}

void heapInit(void* base, size_t bytes) {

    /* can't say new becasue we're initializing the heap */
    array = (int*) base;
    len = bytes / 4;
    makeTaken(0,2);
    makeAvail(2,len-4);
    makeTaken(len-2,2);
}

void* malloc(size_t bytes) {
    //Debug::printf("malloc(%d)\n",bytes);
    if (bytes == 0) return (void*) array;

    int ints = ((bytes + 3) / 4) + 2;
    if (ints < 4) ints = 4;

    void* res = 0;

    int mx = 0x7FFFFFFF;
    int it = 0;

    {
        int countDown = 20;
        int p = avail;
        while (p != 0) {
            if (!isAvail(p)) {
                // there would be a panic here
            }
            int sz = size(p);

            if (sz >= ints) {
                if (sz < mx) {
                    mx = sz;
                    it = p;
                }
                countDown --;
                if (countDown == 0) break;
            }
            p = next(p);
        }
    }

    if (it != 0) {
        remove(it);
        int extra = mx - ints;
        if (extra >= 4) {
            makeTaken(it,ints);
            makeAvail(it+ints,extra);
        } else {
            makeTaken(it,mx);
        }
        res = &array[it+1];
    }

    return res;
}

void free(void* p) {
    if (p == 0) return;
    if (p == (void*) array) return;

    int idx = ((((uintptr_t) p) - ((uintptr_t) array)) / 4) - 1;
    sanity(idx);
    if (!isTaken(idx)) {
        return; // would be a debug panic here but no debug class
    }

    int sz = size(idx);

    int leftIndex = left(idx);
    int rightIndex = right(idx);

    if (isAvail(leftIndex)) {
        remove(leftIndex);
        idx = leftIndex;
        sz += size(leftIndex);
    }

    if (isAvail(rightIndex)) {
        remove(rightIndex);
        sz += size(rightIndex);
    }

    makeAvail(idx,sz);
}

// next few functions may not work, haven't tested 

// void* operator new(size_t size) {
//     void* p =  malloc(size);
//     return p;
// }

// void operator delete(void* p) noexcept {
//     return free(p);
// }

// void operator delete(void* p, size_t sz) {
//     return free(p);
// }

// void* operator new[](size_t size) {
//     void* p =  malloc(size);
//     return p;
// }

// void operator delete[](void* p) noexcept {
//     return free(p);
// }

// void operator delete[](void* p, size_t sz) {
//     return free(p);
// }