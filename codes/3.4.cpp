#include <iostream>
using namespace std;

template <typename T>
void display(T* arr, int size) {
    cout << "Elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
T findMax(T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
void reverseArray(T* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    int size;
    cout << "Enter size of the collection: ";
    cin >> size;

    cout << "Choose data type (1: int, 2: float, 3: char): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        int* arr = new int[size];
        cout << "Enter " << size << " integers:\n";
        for (int i = 0; i < size; i++) cin >> arr[i];

        display(arr, size);
        cout << "Max: " << findMax(arr, size) << endl;
        reverseArray(arr, size);
        cout << "Reversed: ";
        display(arr, size);

        delete[] arr;
    }
    else if (choice == 2) {
        float* arr = new float[size];
        cout << "Enter " << size << " float values:\n";
        for (int i = 0; i < size; i++) cin >> arr[i];

        display(arr, size);
        cout << "Max: " << findMax(arr, size) << endl;
        reverseArray(arr, size);
        cout << "Reversed: ";
        display(arr, size);

        delete[] arr;
    }
    else if (choice == 3) {
        char* arr = new char[size];
        cout << "Enter " << size << " characters:\n";
        for (int i = 0; i < size; i++) cin >> arr[i];

        display(arr, size);
        cout << "Max: " << findMax(arr, size) << endl;
        reverseArray(arr, size);
        cout << "Reversed: ";
        display(arr, size);

        delete[] arr;
    }
    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
