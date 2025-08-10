#include <iostream>
using namespace std;

int recursiveSum(int arr[], int size) {
    if (size == 0)
        return 0;
    return arr[size - 1] + recursiveSum(arr, size - 1);
}

int iterativeSum(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int recSum = recursiveSum(arr, n);
    int iterSum = iterativeSum(arr, n);

    cout << "Recursive Sum: " << recSum << endl;
    cout << "Iterative Sum: " << iterSum << endl;

    delete[] arr;
    return 0;
}
