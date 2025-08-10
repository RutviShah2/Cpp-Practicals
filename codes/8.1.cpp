#include <iostream>
#include <vector>

int main() {
    std::vector<int> sequence;
    int n, element;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> element;
        sequence.push_back(element);
    }

    std::cout << "Reversed sequence using iterators: ";
    for (auto it = sequence.end() - 1; it >= sequence.begin(); --it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
