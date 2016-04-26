//
// Created by Justin on 4/26/16.
//

#include <cmath>
#include <stdlib.h>
#include "mem_allocator.h"

Block::Block(int size) {
    ptr = malloc(size);
    // set free mask = 0
    free_mask = (uint64_t *) calloc(std::ceil(size / FREE_MASK_TYPE_MAX), sizeof(FREE_MASK_TYPE));
}

Block::~Block() {
    free();
}

void Block::free() {
}


//const vector<void *> virtual_memory_blocks;
//int free_block_position = 0;
//
//int get_block_size(int bytes_in_struct) {
//    /***Finds lowest common multiple of `bytes_in_struct` and `bytes_from_os`
//
//     Parameters
//     ----------
//      bytes_in_stuct : int
//          size of struct
//      bytes_from_os : int
//          number of bytes allocated by OS at one time
//
//     Returns
//     -------
//      lcm : int
//          lowest common multiple of `bytes_in_struct` and `bytes_from_os`
//    ***/
//
//    int bytes_from_os = get_size_of_os_pointer();
//    int lcm = (bytes_in_struct > bytes_from_os) ? bytes_in_struct : bytes_from_os;
//
//    do {
//        if (lcm%bytes_in_struct == 0 && lcm%bytes_from_os == 0) {
//            break;
//        }
//        else
//            ++lcm;
//    }
//    while (true);
//
//    return lcm;
//}
//

//
//
//void get_new_block(){
//    /***
//
//        Gets a number of bytes from OS that will be used a block of nodes
//        in virtual memory space. Then adds a pointer to that block to the
//        vector of block pointers virtual_memory_blocks.
//
//    ***/
//    new_block * = malloc(get_block_size(MEMMG_WIDTH * 4))
//
//    virtual_memory_blocks.push_back (new_block);   // adds new_block to end of vector
//}
//

MemoryAllocator::MemoryAllocator(int struct_size) {
    get_block_size(struct_size);
}

MemoryAllocator::~MemoryAllocator() {
    for (auto block : blocks) {
        block->free();
    }
}

void *MemoryAllocator::allocate() {
}

/**
 * Gets a number of bytes from OS that will be used a block of nodes
 * in virtual memory space. Then adds a pointer to that block to the
 * vector of block pointers virtual_memory_blocks.
 */
void MemoryAllocator::getBlock() { }

/**
 * Gets optimal minimal block size based upon multiples
 * of struct and pointer sizes in bytes.
 */
int MemoryAllocator::get_block_size(int struct_size) {
    int pointer_size = sizeof(void *);
    int lcm = (struct_size > pointer_size) ? struct_size : pointer_size;

    do {
        if (lcm % struct_size == 0 && lcm % pointer_size == 0) {
            break;
        }
        else
            ++lcm;
    }
    while (true);

    return lcm;
}