#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

    double getArea() {
        return length * width;
    }

    double getPerimeter() {
        return 2 * (length + width);
    }

    void show(int index) {
        cout << "Rectangle " << index + 1 << " - Length: " << length
             << ", Width: " << width
             << ", Area: " << getArea()
             << ", Perimeter: " << getPerimeter() << endl;
    }
};

int main() {
    Rectangle rects[5];

    rects[0].setDimensions(10.0, 5.0);
    rects[1].setDimensions(8.5, 4.0);
    rects[2].setDimensions(6.0, 6.0);
    rects[3].setDimensions(12.0, 3.5);
    rects[4].setDimensions(7.0, 2.0);

    for (int i = 0; i < 5; i++) {
        rects[i].show(i);
    }

    return 0;
}
