#include <stdint.h>

uint64_t memmg_alloc();

class memmg_ptr {
public:
    memmg_ptr();
    memmg_ptr(uint64_t virt_addr);
    MEMMG_TYPE & operator* ();
    MEMMG_TYPE * operator-> ();
private:
    unsigned char _pointer[MEMMG_WIDTH];
};
