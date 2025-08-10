#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor called" << endl;
    }

    virtual ~Base() {  // <- THIS is the hero!
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        data = new int[100];  // dynamic allocation
        cout << "Derived constructor called (allocated memory)" << endl;
    }

    ~Derived() {
        delete[] data;  // freeing the memory
        cout << "Derived destructor called (freed memory)" << endl;
    }
};

int main() {
    Base* ptr = new Derived();  // Upcasting
    delete ptr;  // If Base's destructor is not virtual, Derived's won't be called — LEAK!
    return 0;
}
