#include <iostream>
#include <vector>
#include <string>

#include "memmg.h"

using namespace std;


int64_t memmg_to_virtual(MEMMG_TYPE *ptr) {
    // Convert a hardware address to a virtual address.
}

MEMMG_TYPE *memmg_reference(char *small_pointer) {
    // convert the virtual pointer into a reference, use MEMMG_WIDTH to
    // determine how far to read in the small_pointer.
}


MemmgPointer::MemmgPointer(MEMMG_TYPE *ptr) {
    int64_t virtual_address;
    _pointer = (char *) malloc(MEMMG_WIDTH);
    virtual_address = memmg_to_virtual(ptr);
    // do some bitmasking here to apply the virtual_address to the _pointer
    // array
}

MEMMG_TYPE &MemmgPointer::operator* () {
    return *memmg_reference(_pointer);
}

MEMMG_TYPE *MemmgPointer::operator-> () {
    return memmg_reference(_pointer);
}