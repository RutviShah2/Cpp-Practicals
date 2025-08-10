#include <iostream>
using namespace std;

long long digitSum(string n) {
    long long sum = 0;
    for (char ch : n) {
        sum += ch - '0';
    }
    return sum;
}

int superDigit(long long n) {
    if (n < 10) return n;

    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return superDigit(sum);
}

int main() {
    string n;
    long long k;
    cin >> n >> k;

    long long initialSum = digitSum(n);
    long long totalSum = initialSum * k;

    cout << superDigit(totalSum) << endl;

    return 0;
}
