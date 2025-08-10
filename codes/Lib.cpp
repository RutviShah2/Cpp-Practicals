#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book
{
public:
    string bookID, title, author, category, type;

    void inputDetails()
    {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Type (Fiction/NonFiction): ";
        cin >> type;
        cout << "Enter Category: ";
        cin.ignore();
        getline(cin, category);
    }

    void displayDetails()
    {
        cout << "Book ID: " << bookID << ", Title: " << title << ", Author: " << author
             << ", Type: " << type << ", Category: " << category << endl;
    }

    string getRecord()
     {
        return bookID + "," + title + "," + author + "," + type + "," + category;
    }
};

void addBook()
 {
    Book book;
    book.inputDetails();

    ifstream checkFile("books.txt");
    string line;
    while (getline(checkFile, line)) {
        if (line.find(book.bookID + ",") == 0) {
            cout << "Error: Book ID already exists!\n";
            return;
        }
    }
    checkFile.close();

    ofstream file("books.txt", ios::app);
    file << book.getRecord() << endl;
    file.close();

    cout << "Book added successfully!\n";
}

void displayBooks() {
    ifstream file("books.txt");
    if (!file) {
        cout << "Error: Unable to open books.txt\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        found = true;
        cout << line << endl;
    }
    file.close();

    if (!found) cout << "No records found.\n";
}

void calculateFine() {
    string type;
    int borrowDay, borrowMonth, borrowYear, returnDay, returnMonth, returnYear;

    cout << "Enter book type (Fiction/NonFiction): "; cin >> type;
    cout << "Enter borrowing date (dd mm yyyy): "; cin >> borrowDay >> borrowMonth >> borrowYear;
    cout << "Enter return date (dd mm yyyy): "; cin >> returnDay >> returnMonth >> returnYear;

    int days = (returnYear - borrowYear) * 360 + (returnMonth - borrowMonth) * 30 + (returnDay - borrowDay);
    int fine = 0;

    if (days > 7) {
        fine = (type == "Fiction") ? ((days > 15) ? (15*8 + 20*(days-15)) : 15*(days-7))
                                   : ((days > 15) ? (10*8 + 15*(days-15)) : 10*(days-7));
    }

    cout << "Total Fine: " << fine << " Rupees\n";
}

int main()
{
    int choice;
    while (true)
        {
        cout << "\nLibrary Management System:\n1. Add New Book\n2. Display all Books\n3. Calculate Fine\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: calculateFine(); break;
            case 4: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
