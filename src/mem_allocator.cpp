//
// Created by Justin on 4/26/16.
//

#include <cmath>
#include <stdlib.h>
#include "mem_allocator.h"

Block::Block(int size) {
    ptr = malloc(size);

    // set free mask
    free_mask = (uint64_t *) calloc(std::ceil(size / FREE_MASK_TYPE_MAX), sizeof(FREE_MASK_TYPE));
}

Block::~Block() {
    free(ptr);
    free((void*)free_mask);
}


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

MemoryAllocator::MemoryAllocator(int size) {
    struct_size = size;
    get_block_size(struct_size);
}

MemoryAllocator::~MemoryAllocator() {
    blocks.clear();
}

void *MemoryAllocator::allocate() {
}

/**
 * Gets a number of bytes from OS that will be used a block of nodes
 * in virtual memory space. Then adds a pointer to that block to the
 * vector of block pointers virtual_memory_blocks.
 */
void MemoryAllocator::getBlock() {
    blocks.push_back (new Block(struct_size));   // adds new Block to end of vector
}

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