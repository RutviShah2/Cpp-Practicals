#include<iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    void setDetails(int pid, string pname, int qty, double pr) {
        id = pid;
        name = pname;
        quantity = qty;
        price = pr;
    }

    void updateQuantity(int change) {
        quantity += change;
    }

    double getValue() {
        return quantity * price;
    }

    void show() {
        cout << "ID: " << id << ", Name: " << name
             << ", Quantity: " << quantity << ", Price: " << price << endl;
    }
};

class Inventory {
private:
    Product products[10];
    int count;

public:
    Inventory() {
        count = 0;
    }

    void addProduct(int id, string name, int qty, double price) {
        if (count < 10) {
            products[count].setDetails(id, name, qty, price);
            count++;
        }
    }

    void updateQuantity(int index, int change) {
        if (index >= 0 && index < count) {
            products[index].updateQuantity(change);
        }
    }

    void showAll() {
        for (int i = 0; i < count; i++) {
            products[i].show();
        }
    }

    double totalValue() {
        double sum = 0;
        for (int i = 0; i < count; i++) {
            sum += products[i].getValue();
        }
        return sum;
    }
};

int main() {
    Inventory store;

    store.addProduct(1, "Pen", 40, 2.5);
    store.addProduct(2, "Notebook", 25, 3.0);
    store.addProduct(3, "Scale", 15, 1.5);

    store.updateQuantity(1, 10);
    store.updateQuantity(0, -5);

    store.showAll();

    cout << "Total Inventory Value: $" << store.totalValue() << endl;

    return 0;
}
