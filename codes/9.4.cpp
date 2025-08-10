#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Custom Exception for Corrupted Data
class CorruptedDataException {
public:
    const char* what() const {
        return "Error: Non-numeric value encountered in numeric context.";
    }
};

// Function to process the file
void processFile(const string& filePath) {
    ifstream file(filePath);
    if (!file) {
        throw runtime_error("File not found.");
    }

    string line;
    int lineNumber = 0;
    double total = 0;

    while (getline(file, line)) {
        ++lineNumber;
        stringstream ss(line);
        double num;
        if (!(ss >> num)) {
            throw CorruptedDataException();
        }
        total += num;
    }

    cout << "\nFile processed successfully.\n";
    cout << "Total sum of numbers: " << total << endl;
    cout << "24CS090_JIGAR SAKHIA" << endl;
}

int main() {
    string path;
    bool success = false;

    while (!success) {
        cout << "Enter file path: ";
        getline(cin, path);

        try {
            processFile(path);
            success = true;
        }
        catch (const runtime_error& e) {
            cout << e.what() << " Please try again.\n";

        }
        catch (const CorruptedDataException& e) {
            cout << e.what() << " Please fix the file and try again.\n";
            break; // Stop on corrupted data
        }
    }
    cout << "24CS090_JIGAR SAKHIA" << endl;

    return 0;


}
