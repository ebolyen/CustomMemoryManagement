//
// Created by Justin on 3/22/16.
//
#include "definitions.h"
#include "memmg.h"
#include "optimized_trie.h"

using namespace std;

OptNode::OptNode() {
    _value = ' ';
}

OptNode::~OptNode() {
    for (int i = 0; i < _children.size(); i++) {
        // delete _children.at(i);
    }
    _children.clear();
}

OptNode *OptNode::get_child(char val) {
    for (int i = 0; i < _children.size(); i++) {
        memmg_ptr temp = _children.at(i);
        if (temp->get_value() == val) {
            return &*temp;
        }
    }

    return NULL;
}

char OptNode::get_value() {
    return _value;
}

void OptNode::set_value(char val) {
    _value = val;
}

void OptNode::append_child(memmg_ptr child) {
    _children.push_back(child);
}


OptTrie::OptTrie() {
    _root = memmg_ptr(memmg_alloc());
    new (&*_root) OptNode();
    _size = 0;
}

OptTrie::~OptTrie(void) {
    // delete _root;
}

void OptTrie::add(string word) {
    OptNode *current = &*_root;

    if (word.length() == 0) {
        return;
    }

    for (int i = 0; i < word.length(); i++) {
        OptNode *child = current->get_child(word[i]);

        if (child == NULL) {
            memmg_ptr temp = memmg_ptr(memmg_alloc());
            new (&*temp) OptNode();
            _size++;
            temp->set_value(word[i]);

            current->append_child(temp);
            current = &*temp;

        } else {
            current = child;
        }
    }
}

bool OptTrie::search(string word) {
    OptNode *current = &*_root;

    for (int i = 0; i < word.length(); i++) {
        OptNode *child = current->get_child(word[i]);

        if (child == NULL) {
            return false;
        } else {
            current = child;
        }
    }

    return true;
}

int OptTrie::get_size() {
    return _size;
};

void OptTrie::clear() {
    // delete _root;
    _root = memmg_ptr(memmg_alloc());
    _size = 0;
}
