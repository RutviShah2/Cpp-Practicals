
#include <iostream>
using namespace std;

class Parent {
public:
    void show()
    {
        cout << "Base Function" << endl;
    }
};

class Child : public Parent {
public:
    void show()
    {
        cout << "Derived Function" << endl;
    }
};

int main()
{

Parent p_Base;
p_Base. show();

    Child Child_Derived;
    Child_Derived. show();

    return 0;
}
