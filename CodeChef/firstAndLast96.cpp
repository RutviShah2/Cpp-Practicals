#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int last = N % 10;  
        int first = N;
        while (first >= 10) {
            first = first / 10; 
        }
        cout << (first + last) << endl;
    }
    return 0;
}
