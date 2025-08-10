#include <iostream>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;

public:
    void addBook() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();  // to clear input buffer
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
    }

    void displayBook() {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author << endl;
    }

    int getBookID() {
        return bookID;
    }
};

int main() {
    Book books[3];
    cout << "Enter details for 3 books:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nBook " << i + 1 << ":\n";
        books[i].addBook();
    }

    cout << "\n--- Book List ---\n";
    for (int i = 0; i < 3; i++) {
        books[i].displayBook();
    }

    return 0;
}
