//
// Created by Justin on 4/24/16.
//

#ifndef CUSTOMMEMORYMANAGEMENT_DEFINITIONS_H
#define CUSTOMMEMORYMANAGEMENT_DEFINITIONS_H

// forward declaration
class OptNode;
#define MEMMG_TYPE OptNode

#ifndef MEMMG_WIDTH
#define MEMMG_WIDTH 5
#endif

// This is aweful
#include "mem_allocator.h"
extern MemoryAllocator *memmg;

#endif //CUSTOMMEMORYMANAGEMENT_DEFINITIONS_H
