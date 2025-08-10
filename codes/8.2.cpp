#include <iostream>
#include <string>
#include <map>
#include <sstream>

int main() {
    std::string sentence;
    std::map<std::string, int> wordFrequency;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::stringstream ss(sentence);
    std::string word;

    while (ss >> word) {
        wordFrequency[word]++;
    }

    std::cout << "Word Frequency Distribution:\n";
    for (const auto& pair : wordFrequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
