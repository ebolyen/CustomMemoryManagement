#include <iostream>
using namespace std;

int get_block_size(int bytes_in_struct, int bytes_from_os) {
    /***Finds lowest common multiple of `bytes_in_struct` and `bytes_from_os`

     Parameters
     ----------
      bytes_in_stuct : int
          size of struct
      bytes_from_os : int
          number of bytes allocated by OS at one time

     Returns
     -------
      lcm : int
          lowest common multiple of `bytes_in_struct` and `bytes_from_os`
    ***/

    int bytes_in_struct, bytes_from_os, lcm;
    cout << "Enter two numbers: ";
    cin >> bytes_in_struct >> bytes_from_os;

    lcm = (bytes_in_struct > bytes_from_os) ? bytes_in_struct : bytes_from_os;

    do {
        if (lcm%bytes_in_struct == 0 && lcm%bytes_from_os == 0) {
            break;
        }
        else
            ++lcm;
    }
    while (true);

    return lcm;
}

void *memmg_alloc() {
    // Allocate a space for a struct, returning the hardware address.
}

int64_t memmg_to_virtual(MEMMG_TYPE *ptr) {
    // Convert a hardware address to a virtual address.
}

MEMMG_TYPE *memmg_reference(char *small_pointer) {
    // convert the virtual pointer into a reference, use MEMMG_WIDTH to
    // determine how far to read in the small_pointer.
}


class MemmgPointer {
public:
    MemmgPointer(MEMMG_TYPE *ptr) {
        int64_t virtual_address;
        _pointer = (char *) malloc(MEMMG_WIDTH);
        virtual_address = memmg_to_virtual(ptr);
        // do some bitmasking here to apply the virtual_address to the _pointer
        // array
    }

    MEMMG_TYPE &operator* () {
        return *memmg_reference(_pointer);
    }

    MEMMG_TYPE *operator-> () {
        return memmg_reference(_pointer);
    }
private:
    char[MEMMG_WIDTH] _pointer;
};
