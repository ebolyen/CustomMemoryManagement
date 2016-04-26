//
// Created by Justin on 4/26/16.
//

#ifndef CUSTOMMEMORYMANAGEMENT_MEM_ALLOCATOR_H
#define CUSTOMMEMORYMANAGEMENT_MEM_ALLOCATOR_H

#include <vector>
#include "definitions.h"


class MemoryAllocator {
public:
    MemoryAllocator();

    ~MemoryAllocator();

    int64_t allocate();

    void free(int64_t);

    void *native(int64_t);

private:
    std::vector<void *> blocks;

    void getBlock();

    void freeBlock(int64_t);

    void clean();
};

#endif //CUSTOMMEMORYMANAGEMENT_MEM_ALLOCATOR_H
