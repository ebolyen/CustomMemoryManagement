//
// Created by Justin on 3/22/16.
//

#ifndef CUSTOMMEMORYMANAGEMENT_TRIE
#define CUSTOMMEMORYMANAGEMENT_TRIE

#include <vector>
#include <string>


class Node {
public:
    Node();

    ~Node();

    Node *get_child(char val);

    char get_value();

    void set_value(char val);

    void append_child(Node *child);

private:
    char _value;
    std::vector<Node *> _children;
};

class Trie {
public:
    void add(std::string word);

    bool search(std::string word);

    Trie();

    ~Trie(void);

    int get_size();

    void clear();

private:
    Node *_root;
    int _size;
};

#endif
