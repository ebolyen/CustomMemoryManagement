//
// Created by Justin on 3/22/16.
//

#ifndef OPTIMIZED_TRIE_H
#define OPTIMIZED_TRIE_H

#include <vector>
#include <string>
#include "memmg.h"

class OptNode {
public:
    OptNode();

    ~OptNode();

    OptNode *get_child(char val);

    char get_value();

    void set_value(char val);

    void append_child(memmg_ptr child);

private:
    char _value;
    std::vector<memmg_ptr> _children;
};

class OptTrie {
public:
    void add(std::string word);

    bool search(std::string word);

    OptTrie();

    ~OptTrie(void);

    int get_size();

    void clear();

private:
    memmg_ptr _root;
    int _size;
};

#endif
