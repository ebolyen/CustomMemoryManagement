//
// Created by Justin on 4/26/16.
//

#include "mem_allocator.h"


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
//int get_size_of_os_pointer(){
//    return sizeof(void*);
//}
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
//void *memmg_alloc() {
//    // Allocate a space for a struct, returning the hardware address.
//}