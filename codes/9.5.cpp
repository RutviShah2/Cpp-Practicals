#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

// Base exception
class LibraryException {
public:
    virtual const char* what() const {
        return "Library exception occurred.";
    }
};

class BookNotFoundException : public LibraryException {
public:
    const char* what() const override {
        return "Book not found in the library.";
    }
};

class MemberNotFoundException : public LibraryException {
public:
    const char* what() const override {
        return "Member ID not found.";
    }
};

class OverdueBookException : public LibraryException {
public:
    const char* what() const override {
        return "Member has overdue books.";
    }
};

class Library {
private:
    map<int, string> books; // bookID -> bookName
    map<int, bool> members; // memberID -> hasOverdueBooks
    queue<pair<int, int>> borrowQueue; // (memberID, bookID)

public:
    Library() {
        // Sample books and members
        books[101] = "C++ Fundamentals";
        books[102] = "Data Structures";
        members[1] = false;
        members[2] = true; // member 2 has overdue book
    }

    void borrowBook(int memberId, int bookId) {
        cout << "Processing borrow request for member " << memberId << " and book " << bookId << endl;

        if (books.find(bookId) == books.end()) {
            throw BookNotFoundException();
        }

        if (members.find(memberId) == members.end()) {
            throw MemberNotFoundException();
        }

        if (members[memberId]) {
            throw OverdueBookException();
        }

        borrowQueue.push({memberId, bookId});
        cout << "Book borrowed successfully: " << books[bookId] << " by member " << memberId << endl;
    }

    void processQueue() {
        cout << "\nBorrow Requests Processed:\n";
        while (!borrowQueue.empty()) {
            auto request = borrowQueue.front();
            borrowQueue.pop();
            cout << "Member " << request.first << " borrowed Book ID " << request.second << " (" << books[request.second] << ")\n";
        }
    }
};

int main() {
    Library lib;

    try {
        lib.borrowBook(1, 101);  // Valid
        lib.borrowBook(2, 101);  // Overdue
    } catch (LibraryException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    try {
        lib.borrowBook(3, 102);  // Invalid member
    } catch (LibraryException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    try {
        lib.borrowBook(1, 999);  // Invalid book
    } catch (LibraryException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    lib.processQueue();
    return 0;
}
