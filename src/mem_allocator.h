#ifndef CUSTOMMEMORYMANAGEMENT_MEM_ALLOCATOR_H
#define CUSTOMMEMORYMANAGEMENT_MEM_ALLOCATOR_H

#include <vector>
#include <stdint.h>


class Block {
public:
    Block(uint64_t addr, int max, int size);

    bool is_full();
    uint64_t get_next_addr();
    void *get_reference_of(int offset);
private:
    void *memory;
    int struct_size;
    int max_count;
    int curr_offset;
    uint64_t root_addr;
};

class MemoryAllocator {
public:
    MemoryAllocator(int struct_size);

    uint64_t allocate();
    void *reference(uint64_t virt_ptr);
private:
    int struct_size;
    int structs_per_block;
    uint64_t next_block_addr;
    std::vector<Block *> blocks;

    Block *addBlock();
    int get_block_size(int struct_size);
};

#endif //CUSTOMMEMORYMANAGEMENT_MEM_ALLOCATOR_H
