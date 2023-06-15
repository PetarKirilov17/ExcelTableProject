#include <iostream>
#include <vector>
#include "stringHelperFunctions.h"

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

std::vector<int> parseIndexes(const char* input) {
    std::vector<int> indexes;

    int row = 0;
    int col = 0;
    bool isParsingRow = false;
    bool isParsingCol = false;

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        if (ch == 'R') {
            isParsingRow = true;
            isParsingCol = false;
            row = 0;
        } else if (ch == 'C') {
            isParsingCol = true;
            isParsingRow = false;
            col = 0;
        } else if (isDigit(ch)) {
            if (isParsingRow) {
                row = row * 10 + (ch - '0');
            } else if (isParsingCol) {
                col = col * 10 + (ch - '0');
            }
        } else {
            if (isParsingRow || isParsingCol) {
                indexes.push_back(row);
                indexes.push_back(col);
            }
            isParsingRow = false;
            isParsingCol = false;
        }
    }

    if (isParsingRow || isParsingCol) {
        indexes.push_back(row);
        indexes.push_back(col);
    }

    return indexes;
}

int main() {
    const char* input = "= R10C3 + 10 + R4C14 - 12 * 47 / R7C10";

    std::vector<int> indexes = parseIndexes(input);

    std::cout << "Parsed indexes:" << std::endl;
    for (size_t i = 0; i < indexes.size(); i += 2) {
        int row = indexes[i];
        int col = indexes[i + 1];
        std::cout << "Row: " << row << ", Column: " << col << std::endl;
    }

    return 0;
}