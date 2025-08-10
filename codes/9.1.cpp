#include <iostream>
using namespace std;

int main() {
    int num, den;

    cout << "Enter numerator and denominator: ";

    // Check for valid input
    if (!(cin >> num >> den)) {
        cout << "Error: Invalid input! Please enter only integer values." << endl;
        return 1;
    }

    // Check for division by zero
    try {
        if (den == 0) {
            throw " Error: Division by zero is not allowed!";
        }

        // Perform division
        double result = static_cast<double>(num) / den;
        cout << "Result: " << result << endl;

    } catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}
