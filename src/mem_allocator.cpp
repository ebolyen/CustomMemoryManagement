//
// Created by Justin on 4/26/16.
//

#include <cmath>
#include <stdlib.h>
#include "mem_allocator.h"

Block::Block(int block_size) {
    size = block_size;
    ptr = malloc(size);

    // set free mask
    free_mask = (FREE_MASK_TYPE *) calloc(get_free_mask_size(), sizeof(FREE_MASK_TYPE));
}

Block::~Block() {
    free(ptr);
    free((void *) free_mask);
}

/**
 * Iterate through slots to find first empty. If none found, return -1.
 */
int Block::get_first_free() {
    for (int i = 0; i < size; i++) {
        if (get_free_mask(i)) {
            return i;
        }
    }

    // return -1 if all 1
    return -1;
}

/**
 * Get the first free slot in the block.
 */
void *Block::get_free_slot() {
    int slot_number = get_first_free();

    if (slot_number == -1) {
        // TODO handle exception
    }

    return free_mask + slot_number;
}

/**
 * Helper function to see if block is full.
 */
bool Block::is_full() {
    return get_first_free() == -1;
}

/**
 * Helper function to get length of free mask array.
 */
int Block::get_free_mask_size() {
    return std::ceil(size / FREE_MASK_TYPE_MAX);
}

/**
 * Get the value of the free mask corresponding to slot number.
 */
bool Block::get_free_mask(int slot_number){
    int mask_size = get_free_mask_size();
    int mask_part_size = sizeof(FREE_MASK_TYPE);

    // TODO Test this
    return (*(free_mask + slot_number / mask_part_size) & (0 << slot_number % mask_part_size));
}

/**
 * Set bit of free mask to 1 if is full else 0.
 */
void Block::set_free_mask(int slot_number, bool is_full) {
    int mask_size = get_free_mask_size();
    int mask_part_size = sizeof(FREE_MASK_TYPE);
    // TODO
}


MemoryAllocator::MemoryAllocator(int size) {
    struct_size = size;
    block_size = get_block_size(struct_size);
}

MemoryAllocator::~MemoryAllocator() {
    blocks.clear();
}

void *MemoryAllocator::allocate() {
    // TODO improve so only a single iteration of free mask is needed
    if (blocks.size() == 0 || blocks.back()->is_full()) {
        getBlock();
    }
    Block *b = blocks.back();
    return b->get_free_slot();
}

/**
 * Gets a number of bytes from OS that will be used a block of nodes
 * in virtual memory space. Then adds a pointer to that block to the
 * vector of block pointers virtual_memory_blocks.
 */
Block *MemoryAllocator::getBlock() {
    Block *b = new Block(block_size);
    blocks.push_back(b);   // adds new Block to end of vector

    // TODO track free blocks

    return b;
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