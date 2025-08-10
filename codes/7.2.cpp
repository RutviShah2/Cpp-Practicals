 #include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int isAlphabetOrDigit(char ch) {
    return ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'));
}

int main() {
    const int MAX_LINES = 10000;
    const int MAX_LENGTH = 1000;

    char filename[100];
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename);
    while (!file) {
        cout << "Error: Could not open the file.\nPlease re-enter filename: ";
        cin >> filename;
        file.open(filename);
    }

    char** lines = new char*[MAX_LINES];
    int lineCount = 0, charCount = 0, wordCount = 0;
    char buffer[MAX_LENGTH];

    while (file.getline(buffer, MAX_LENGTH)) {
        int len = strlen(buffer);
        lines[lineCount] = new char[len + 1];
        strcpy(lines[lineCount], buffer);
        lineCount++;
        charCount += len;

        int i = 0;
        while (buffer[i]) {
            while (buffer[i] && !isAlphabetOrDigit(buffer[i])) i++;
            if (buffer[i]) {
                wordCount++;
                while (buffer[i] && isAlphabetOrDigit(buffer[i])) i++;
            }
        }
    }

    file.close();

    cout << "Total Characters (excluding newlines): " << charCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Lines: " << lineCount << endl;

    for (int i = 0; i < lineCount; i++) {
        delete[] lines[i];
    }
    delete[] lines;

    cout << "24CS090_JIGAR SAKHIA" << endl;
    return 0;
}
