#include <iostream>
#include <vector>
#include <string>


class Memmg {
public:
    int get_block_size();

    int get_size_of_os_pointer();

    void * get_new_block();

private:
    std::vector<void *> blocks;

};
