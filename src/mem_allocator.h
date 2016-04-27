//
// Created by Justin on 4/26/16.
//

#ifndef CUSTOMMEMORYMANAGEMENT_MEM_ALLOCATOR_H
#define CUSTOMMEMORYMANAGEMENT_MEM_ALLOCATOR_H

#include <vector>
#include "definitions.h"

#define FREE_MASK_TYPE uint64_t
#define FREE_MASK_TYPE_MAX UINT64_MAX


class Block {
public:
    Block(int block_size);

    ~Block();

    void *get_free_slot();
    bool is_full();
    int get_first_free();

private:
    void *ptr;
    int size;
    FREE_MASK_TYPE *free_mask; // depends on block size
    int get_free_mask_size();
    bool get_free_mask(int slot_number);
    void set_free_mask(int slot_number, bool is_full);
};

class MemoryAllocator {
public:
    MemoryAllocator(int struct_size);

    ~MemoryAllocator();

    void *allocate();

    void free(int64_t);

    void *native(int64_t);

private:
    int struct_size;
    int block_size;
    std::vector<Block *> blocks;

    Block *getBlock();

    void freeBlock(int64_t);

    void clean();

    int get_block_size(int struct_size);
};

#endif //CUSTOMMEMORYMANAGEMENT_MEM_ALLOCATOR_H
