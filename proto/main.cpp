#include <stdint.h>
#include <stdlib.h>
#include <iostream>


using namespace std;


class Something {
public:
    Something(double a, double b) {
        x = a;
        y = b;
    }
    double get_x() {
        return x;
    }
    double get_y() {
        return y;
    }
private:
    double x;
    double y;
};

class SmartPointer {
public:
    SmartPointer(int64_t ptr) {
        _pointer = (Something *) ptr;
    }
    Something & operator* () {
        return *_pointer;
    }
    Something * operator-> () {
        return _pointer;
    }
private:
    Something *_pointer;
};

int64_t allocate() {
    return (int64_t) malloc(sizeof(Something));
}


int main(int argc, char **argv) {
    // Demonstration of using a smart pointer where allocate does not return
    // a pointer type.
    SmartPointer ptr = SmartPointer(allocate());
    new (&*ptr) Something(1.1, 2.2);
    cout << ptr->get_x() << endl;
    cout << ptr->get_y() << endl;


    return 0;
}
