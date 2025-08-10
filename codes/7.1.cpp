#include <iostream>
#include <cstring>

using namespace std;

struct Word {
    char* text;
    int count;
};

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

int areEqual(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

int isAlphabetOrDigit(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return 1;
    else
        return 0;
}

int main() {
    const int BUFFER_SIZE = 10000;
    char* paragraph = new char[BUFFER_SIZE];
    cin.getline(paragraph, BUFFER_SIZE);

    Word* words = new Word[10];
    int capacity = 10;
    int size = 0;

    int i = 0;
    while (paragraph[i]) {
        while (paragraph[i] && !isAlphabetOrDigit(paragraph[i])) i++;

        char temp[100];
        int j = 0;
        while (paragraph[i] && isAlphabetOrDigit(paragraph[i])) {
            temp[j++] = paragraph[i++];
        }
        temp[j] = '\0';

        if (j > 0) {
            toLowerCase(temp);

            int found = 0;
            for (int k = 0; k < size; k++) {
                if (areEqual(words[k].text, temp)) {
                    words[k].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                if (size == capacity) {
                    capacity *= 2;
                    Word* newWords = new Word[capacity];
                    for (int k = 0; k < size; k++) {
                        newWords[k] = words[k];
                    }
                    delete[] words;
                    words = newWords;
                }
                words[size].text = new char[strlen(temp) + 1];
                strcpy(words[size].text, temp);
                words[size].count = 1;
                size++;
            }
        }
    }

    for (int k = 0; k < size; k++) {
        cout << words[k].text << ": " << words[k].count << endl;
    }

    for (int k = 0; k < size; k++) {
        delete[] words[k].text;
    }
    delete[] words;
    delete[] paragraph;

    return 0;
}
