#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point* shift(int dx, int dy) {
        x += dx;
        y += dy;
        return this;
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p(5, 10);

    p.shift(2, 3)->shift(-1, 0)->shift(4, -2);

    cout << "Final Position: ";
    p.display();

    return 0;
}
