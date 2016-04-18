//
// Created by Justin on 4/17/16.
//

#ifndef CUSTOMMEMORYMANAGEMENT_COMPACTPOINTER_H
#define CUSTOMMEMORYMANAGEMENT_COMPACTPOINTER_H

template<class T>
class CompactPointer {
public:
    CompactPointer(T *ptr) : value(ptr) {
    }

    T &operator* () {
        return *value;
    }

    T *operator-> () {
        return value;
    }

private:
    T*    value;
};

#endif //CUSTOMMEMORYMANAGEMENT_COMPACTPOINTER_H
