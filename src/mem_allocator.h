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
    Block(int size);

    ~Block();

private:
    void *ptr;
    FREE_MASK_TYPE *free_mask; // depends on block size
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
    std::vector<Block *> blocks;

    void getBlock();

    void freeBlock(int64_t);

    void clean();

    int get_block_size(int struct_size);
};

#endif //CUSTOMMEMORYMANAGEMENT_MEM_ALLOCATOR_H
