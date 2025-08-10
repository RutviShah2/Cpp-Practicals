#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    friend istream& operator>>(istream& in, Complex& c) {
        in >> c.real >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return out;
    }
};

int main() {
    const int n = 3;
    Complex a[n], sum, diff;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum = sum + a[i];
        diff = diff - a[i];
    }

    cout << "Total Sum: " << sum << "\n";
    cout << "Total Difference: " << diff << "\n";

    return 0;
}
