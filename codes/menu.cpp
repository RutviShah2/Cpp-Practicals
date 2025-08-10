#include <iostream>
using namespace std;

int main() {
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Greet\n";
        cout << "2. Add two numbers\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Hiiiii Rutvii! 🥰" << endl;
                break;
            case 2:
                int a, b;
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Sum = " << a + b << endl;
                break;
            case 3:
                cout << "Exiting... Bye bye!! 👋" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 3);

    return 0;
}
