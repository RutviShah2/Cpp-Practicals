#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--)
     {
        int N;
        cin >> N;
        cout << (int)ceil((double)N / 4) << endl;
    }
    return 0;
}