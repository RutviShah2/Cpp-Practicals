#include <iostream>
using namespace std;
int main() {
    int X, Y;
    cin >> X >> Y; 
    int clearDays = 7 - X - Y; 
    cout << clearDays << endl;
    return 0;
}
