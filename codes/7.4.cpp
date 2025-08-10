#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

void printStudentRecord(const string& name, int marks, char grade) {
    // Print formatted student data
    cout << left << setw(15) << name;   // Name column with fixed width
    cout << setw(10) << marks;          // Marks column
    cout << grade << endl;              // Grade
}

int main() {
    ifstream file("hello.cpp");  // File to read student data from

    if (!file) {
        cerr << "Error: File could not be opened!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int marks;
        char grade;

        ss >> name >> marks >> grade;
        printStudentRecord(name, marks, grade);
    }

    file.close();
    cout << "24CS090_JIGAR SAKHIA" << endl;
    return 0;
}
