#define ONE_BYTE = 1

#include <iostream>
#include <vector>
#include <string>

#include "memmg.h"

using namespace std;

vector<void *> blocks;

int get_block_size(int bytes_in_struct) {
    /***Finds lowest common multiple of `bytes_in_struct` and `bytes_from_os`

     Parameters
     ----------
      bytes_in_stuct : int
          size of struct
      bytes_from_os : int
          number of bytes allocated by OS at one time

     Returns
     -------
      lcm : int
          lowest common multiple of `bytes_in_struct` and `bytes_from_os`
    ***/

    int bytes_from_os = Memmg->get_size_of_os_pointer();
    int lcm = (bytes_in_struct > bytes_from_os) ? bytes_in_struct : bytes_from_os;

    do {
        if (lcm%bytes_in_struct == 0 && lcm%bytes_from_os == 0) {
            break;
        }
        else
            ++lcm;
    }
    while (true);

    return lcm;
}


int get_size_of_os_pointer(){
    return sizeof(void*);
}


void get_new_block(){

    new_block * = calloc(ONE_BYTE, get_block_size(MEMMG_WIDTH * 4))

    blocks.push_back (new_block);   // adds new_block to end of vector
}
