#include <iostream>
using namespace std;

void mergeSortedArrays(int* a, int n, int* b, int m, int*& result, int& size) {
    size = n + m;
    result = new int[size];

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < n)
        result[k++] = a[i++];

    while (j < m)
        result[k++] = b[j++];
}

int main() {
    int n, m;
    cin >> n;
    int* arr1 = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr1[i];

    cin >> m;
    int* arr2 = new int[m];
    for (int i = 0; i < m; ++i)
        cin >> arr2[i];

    int* merged = nullptr;
    int mergedSize = 0;

    mergeSortedArrays(arr1, n, arr2, m, merged, mergedSize);

    for (int i = 0; i < mergedSize; ++i)
        cout << merged[i] << " ";
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}
