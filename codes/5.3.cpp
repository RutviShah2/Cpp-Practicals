#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    int operator==(const Point& other) const {
        return (x == other.x && y == other.y) ? 1 : 0;
    }

    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(3, 4), p2(1, 2), p3;

    p3 = p1 + p2;
    cout << "p1 + p2 = "; p3.print();

    p3 = -p3;
    cout << "After negating p3: "; p3.print();

    p3 = p1 + p2;
    cout << "p1 + p2 again = "; p3.print();

    if (p1 == p2) {
        cout << "p1 and p2 are the same." << endl;
    } else {
        cout << "p1 and p2 are different." << endl;
    }

    return 0;
}
