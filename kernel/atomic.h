#ifndef _ATOMIC_H_
#define _ATOMIC_H_
// probably needs an include in order for our atomic class to work

// this atomic class will just use ints since objective C doesn't have generic type
struct Atomic {
    
    // TODO: don't know why there is an error 

    int fetch_add(int inc) {
        return __atomic_fetch_add(&value,inc,__ATOMIC_SEQ_CST);
    }

    int add_fetch(int inc) {
        return __atomic_add_fetch(&value,inc,__ATOMIC_SEQ_CST);
    }

    void set(int inc) {
        return __atomic_store_n(&value,inc,__ATOMIC_SEQ_CST);
    }

    int get() {
        return __atomic_load_n(&value,__ATOMIC_SEQ_CST);
    }

    int exchange(int v) {
        int ret;
        __atomic_exchange(&value,&v,&ret,__ATOMIC_SEQ_CST);
        return ret;
    }
};

#endif