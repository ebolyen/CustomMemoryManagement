#include <iostream>


// Project Specific
#include "compactPointer.h"
#include "trie.h"

int main(int argc, char **argv) {
    std::cout << "Test Smart gitPointer to Trie" << "\n";

    CompactPointer<Trie> prefix = new Trie();
    std::cout << "Pointer size: " << sizeof(&prefix) << "\n";;

    prefix->add("Hello World");
    std::cout << "Prefix Length: " << prefix->get_size() << "\n";

    return 0;
}