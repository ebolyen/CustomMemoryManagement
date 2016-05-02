#include "shared.h"
#include "../src/memmg.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

class LinkedList {
public:
    int value;
    memmg_ptr next;

    LinkedList(int x) {
        value = x;
    }

    memmg_ptr *append(int x) {
        next = memmg_ptr(memmg_alloc());
        new (&*next) LinkedList(x);
        return &next;
    }
};
MemoryAllocator *memmg;

int main(int argc, char **argv) {
    memmg = new MemoryAllocator(sizeof(MEMMG_TYPE));
    memmg_ptr root = memmg_ptr(memmg_alloc());
    new (&*root) LinkedList(0);

    memmg_ptr p = root;
    int i;
    for(i=1; i < 1400; i++) {
        p = *p->append(i);
    }
    p = root;
    while(&*p) {
        // cout << &*p << endl;
        // cout << (*p).value << endl;
        p = p->next;
    }
}
