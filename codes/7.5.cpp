#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// User-defined manipulator for currency formatting
ostream& currency(ostream& os) {
    return os << "₹ ";  // You can change this to "$" or any other currency symbol
}

int main() {
    ifstream file("hello.cpp");  // Open the file containing student data

    if (!file) {
        cerr << "Error: File could not be opened!" << endl;
        return 1;
    }

    string name;
    int marks;

    cout << "Student Report\n\n";

    // Read student name and marks from the file
    while (file >> name >> marks) {
        cout << left << setw(20) << name     // Name column (left-aligned, 20 width)
             << setw(10) << marks << endl;   // Marks column (10 width)
    }

    // Display Tuition Fees
    double fee = 15000.75;  // Example tuition fee
    cout << "\nTuition Fees\n\n";
    cout << setw(15) << currency << fixed << setprecision(2) << fee << endl;

    file.close();
    cout << "24CS090_JIGARSAKHIA" << endl;
    return 0;
}
