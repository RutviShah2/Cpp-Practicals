#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Product {
    char name[50];
    int quantity;
    float price;
};

void addProduct(const char* filename) {
    Product p;
    cout << "Enter product name: ";
    cin.ignore();
    cin.getline(p.name, 50);
    cout << "Enter quantity: ";
    cin >> p.quantity;
    cout << "Enter price: ";
    cin >> p.price;

    ofstream file(filename, ios::binary | ios::app);
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return;
    }
    file.write((char*)&p, sizeof(Product));
    file.close();
}

void viewInventory(const char* filename) {
    Product p;
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Error opening file for reading." << endl;
        return;
    }

    cout << "\nInventory List:\n" << endl;
    while (file.read((char*)&p, sizeof(Product))) {
        cout << "Name: " << p.name << endl;
        cout << "Quantity: " << p.quantity << endl;
        cout << "Price: " << p.price << endl;
        cout << "-----------------------------" << endl;
    }

    file.close();
}

void searchProduct(const char* filename) {
    char searchName[50];
    cout << "Enter product name to search: ";
    cin.ignore();
    cin.getline(searchName, 50);

    Product p;
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Error opening file for reading." << endl;
        return;
    }

    int found = 0;
    while (file.read((char*)&p, sizeof(Product))) {
        if (strcmp(p.name, searchName) == 0) {
            cout << "Product Found:" << endl;
            cout << "Name: " << p.name << endl;
            cout << "Quantity: " << p.quantity << endl;
            cout << "Price: " << p.price << endl;
            cout << "24CS090_JIGARSAKHIA" << endl;
            found = 1;
            break;
        }
    }

    if (!found) {
        cout << "Product not found." << endl;
    }

    file.close();
}

int main() {
    const char* filename = "inventory.dat";
    int choice;

    do {
        cout << "\nInventory Management System" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Inventory" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(filename);
                break;
            case 2:
                viewInventory(filename);
                break;
            case 3:
                searchProduct(filename);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    cout << "24CS090_JIGAR SAKHIA" << endl;
    return 0;
}
