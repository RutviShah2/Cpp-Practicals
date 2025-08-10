#include <iostream>
#include <cmath> // For sqrt function
using namespace std;

// Custom exception class
class NegativeNumberException {
public:
    const char* what() const {
        return "Error: Cannot calculate square root of a negative number.";
    }
};

int main() {
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        cout << "\nEnter a number to calculate its square root: ";
        double num;
        cin >> num;

        try {
            if (num < 0) {
                throw NegativeNumberException();
            }

            double result = sqrt(num);
            cout << "Square root of " << num << " is: " << result << endl;

        } catch (NegativeNumberException& e) {
            cout << e.what() << endl;
        }

        cout << "Do you want to enter another number? (y/n): ";
        cin >> choice;
    }

    cout << "Program ended." << endl;
    return 0;
}
