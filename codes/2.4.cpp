#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Item() {
        id = 0;
        name = "Unnamed";
        price = 0.0;
        quantity = 0;
    }

    Item(int itemId, string itemName, double itemPrice, int itemQty) {
        id = itemId;
        name = itemName;
        price = itemPrice;
        quantity = itemQty;
    }

    void addStock(int amount) {
        if (amount > 0) {
            quantity += amount;
        }
    }

    void sell(int amount) {
        if (amount <= quantity) {
            quantity -= amount;
        } else {
            cout << "Not enough stock for item: " << name << endl;
        }
    }

    void display() {
        cout << "Item ID: " << id << ", Name: " << name
             << ", Price: $" << price << ", Quantity: " << quantity << endl;
    }
};

int main() {
    Item items[3] = {
        Item(),
        Item(101, "Shampoo", 5.99, 20),
        Item(102, "Toothpaste", 2.49, 15)
    };

    items[0] = Item(100, "Soap", 1.99, 30);

    items[0].sell(5);
    items[1].addStock(10);
    items[2].sell(20);
    items[2].addStock(5);

    for (int i = 0; i < 3; i++) {
        items[i].display();
    }

    return 0;
}
