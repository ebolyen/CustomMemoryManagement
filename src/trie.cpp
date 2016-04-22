//
// Created by Justin on 3/22/16.
//

#include "trie.h"

using namespace std

Node::Node() {
    _value = ' ';
}

Node::~Node() {
    for (int i = 0; i < _children.size(); i++) {
        delete _children.at(i);
    }
    _children.clear();
}

Node *Node::get_child(char val) {
    for (int i = 0; i < _children.size(); i++) {
        Node *temp = _children.at(i);
        if (temp->get_value() == val) {
            return temp;
        }
    }

    return NULL;
}

char Node::get_value() {
    return _value;
}

void Node::set_value(char val) {
    _value = val;
}

void Node::append_child(Node *child) {
    _children.push_back(child);
}


Trie::Trie() {
    _root = new Node();
    _size = 0;
}

Trie::~Trie(void) {
    delete _root;
}

void Trie::add(string word) {
    Node *current = _root;

    if (word.length() == 0) {
        return;
    }

    for (int i = 0; i < word.length(); i++) {
        Node *child = current->get_child(word[i]);

        if (child == NULL) {
            Node *temp = new Node();
            _size++;
            temp->set_value(word[i]);

            current->append_child(temp);
            current = temp;

        } else {
            current = child;
        }
    }
}

bool Trie::search(string word) {
    Node *current = _root;

    for (int i = 0; i < word.length(); i++) {
        Node *child = current->get_child(word[i]);

        if (child == NULL) {
            return false;
        } else {
            current = child;
        }
    }

    return true;
}

int Trie::get_size() {
    return _size;
};

void Trie::clear() {
    delete _root;
    _root = new Node();
    _size = 0;
}
