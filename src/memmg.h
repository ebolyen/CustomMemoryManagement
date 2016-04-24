<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <string>


class Memmg {
public:
    int get_block_size();

    int get_size_of_os_pointer();

    void * get_new_block();

private:
    std::vector<void *> blocks;

=======
/* Allocation will look like:
 * MemmgPointer my_ptr;
 * my_ptr = MemmgPointer(new(memmg_alloc()) OurClassType(1, 2, 3));
 *
 * Care should be taken to ensure that a pointer to MemmgPointer is not used,
 * instead place it directly in any structs.
 */

void * memmg_alloc();

class MemmgPointer {
public:
    MemmgPointer(MEMMG_TYPE *ptr);
    MEMMG_TYPE & operator* ();
    MEMMG_TYPE * operator-> ();
private:
    char[MEMMG_WIDTH] _pointer;
>>>>>>> ab16e73fdd83e36fad64fd207b1cac72acfdb6ff
};
