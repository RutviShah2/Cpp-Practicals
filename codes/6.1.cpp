#include <iostream>
using namespace std;

class DynamicArray {
    int* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for(int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    DynamicArray(int cap = 2) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int value) {
        if(size == capacity)
            resize();
        data[size++] = value;
    }

    void remove(int pos) {
        if(pos < 0 || pos >= size) return;
        for(int i = pos; i < size - 1; ++i)
            data[i] = data[i + 1];
        size--;
    }

    void display() {
        for(int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    int getSize() {
        return size;
    }
};

int main() {
    DynamicArray arr;
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);

    cout << "Array: ";
    arr.display();

    arr.remove(1);
    cout << "After removing position 1: ";
    arr.display();

    arr.insert(50);
    cout << "After inserting 50: ";
    arr.display();

    return 0;
}
