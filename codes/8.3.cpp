#include <iostream>
#include <set>

int main() {
    std::set<int> transactionIDs;
    int n, transactionID;

    std::cout << "Enter the number of transactions: ";
    std::cin >> n;

    std::cout << "Enter the transaction IDs: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> transactionID;
        transactionIDs.insert(transactionID);
    }

    std::cout << "Unique Transaction IDs in sorted order:\n";
    for (auto it = transactionIDs.begin(); it != transactionIDs.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
