//
// Created by Petar on 14.5.2023 г..
//

#include "stringHelperFunctions.h"
#include "cstring"
#include "consts.h"
#include "Utils/StringView.h"

bool StringHelper::tryParseToInt(const MyString &string, int &result) {
    size_t stringLength = string.length();
    for (int i = 0; i <stringLength; ++i) {
        if(!StringHelper::isDigit(string[i]))
            return false;
        result *= 10;
        result+= (string[i] - '0');
    }
    return true;
}

bool StringHelper::isDigit(const char symbol) {
    return symbol >= '0' && symbol <= '9';
}

bool StringHelper::tryParseToDouble(const MyString &string, double &result) {
    size_t stringIndex = 0;
    bool isNegative = false;

    // check for optional sign in the beginning
    if(string[stringIndex] == MINUS_SIGN || string[stringIndex] == PLUS_SIGN){
        isNegative = (string[stringIndex] == MINUS_SIGN);
        stringIndex++;
    }

    // parse the integer part of the number
    while (isDigit(string[stringIndex])){
        result = result * 10.0 + (string[stringIndex] - '0');
        stringIndex++;
    }

    if(string[stringIndex] != DOT_SEPARATOR && string[stringIndex] != COMMA_SEPARATOR){
        return false; // wrong format of the double number
    }
    stringIndex++; // skip the separator

    // Parse fractional part
    double fraction = 0.1;
    while (isDigit(string[stringIndex])){
        result += ((string[stringIndex] - '0') * fraction);
        fraction *= 0.1;
        stringIndex++;
    }

    if(string[stringIndex] != '\0'){
        return false; // there is something else behind the fractional part -> wrong format of the double number
    }

    if(isNegative){
        result = -result;
    }
    return true;
}

void StringHelper::trimStr(const char *src, char *dest) {
    size_t srcIndex = 0;
    size_t destIndex = 0;
    while (src[srcIndex]== ' ' || src[srcIndex] == '\t'){ // skip the leading whitespaces
        srcIndex++;
    }
    size_t srcFinalIndex = strlen(src) - 1;
    while (src[srcFinalIndex] == ' ' || src[srcFinalIndex] == '\t'){ // skip the final whitespaces
        srcFinalIndex--;
    }
    for (int i = srcIndex; i <= srcFinalIndex; ++i) {
        dest[destIndex++] = src[i];
    }
    dest[destIndex] = '\0';
}

bool StringHelper::tryParseToString(const MyString &inputString, MyString &result) {
    char buffer[BUFFER_MAX_SIZE]{'\0'};
    size_t inputStringLength = inputString.length();
    size_t resultIndex = 0;
    if(inputString[0] != '\"' || inputString[inputStringLength-1] != '\"'){
        return false; // wrong format of the string cell
    }
    for (int i = 1; i < inputStringLength - 1; ++i) {
        if(inputString[i] != '\\'){
            buffer[resultIndex++] = inputString[i];
            continue;
        }
        // inputString[i] == '\'
        i++; // we are skipping the first '\'
        if(i >= inputStringLength - 1){
            return false; // out of range of the inputString
        }

        if(inputString[i] == '\\' || inputString[i] == '\"'){
            buffer[resultIndex++] = inputString[i];
        }
        else {
            return false;
        }
    }
    result = buffer;
    return true;
}

bool StringHelper::isFormulaCell(const MyString &string) {
    return string[0] == '=';
}

bool StringHelper::isOperator(const char symbol) {
    return symbol == PLUS_SIGN || symbol == MINUS_SIGN || symbol == MULTIPLY_SIGN || symbol == DIVISION_SIGN || symbol == POW_SIGN;
}

MyString StringHelper::extractNumberFromFormula(const MyString &stringExpr, int start, int &index) {
    while(index < stringExpr.length() &&
    (StringHelper::isDigit(stringExpr[index]) || stringExpr[index] == DOT_SEPARATOR || stringExpr[index] == COMMA_SEPARATOR)){
        index++;
    }
    return stringExpr.substr(start, index - start);
}

int StringHelper::findLength(int number) {
    int length = 0;
    while (number != 0) {
        number /= 10;
        length++;
    }
    return length;
}

int StringHelper::findLength(double number) {

    if (number == 0)
        return 1; // If the number is zero, length is 1 (including the decimal point)

    int length = 0;
    long long intPart = static_cast<long long>(number); // Extract the integer part
    long long initialIntPart = intPart;
    // Calculate the length of the integer part
    while (intPart != 0) {
        intPart /= 10;
        length++;
    }

    if(initialIntPart == number){
        return length;
    }

    length++; // Account for the decimal point

    double decimalPart = number - static_cast<double>(initialIntPart); // Extract the decimal part

    // Calculate the length of the decimal part
    while (decimalPart - static_cast<long long>(decimalPart) != 0) {
        decimalPart *= 10;
        length++;
    }

    return length;
}

void StringHelper::printSymbolNTimes(char symbol, size_t times) {
    for (int i = 0; i < times; ++i) {
        std::cout << symbol;
    }
}

MyString StringHelper::convertStringCellForOutput(const MyString &string) {
    char buffer[BUFFER_MAX_SIZE]{'\0'};
    buffer[0] = '"';
    int index = 1;
    for (int i = 0; i < string.length() ; ++i) {
        if (string[i] == '\\' || string[i] == '"') {
            buffer[index++] = '\\';
            buffer[index++] = string[i];
        }
        else
            buffer[index++] = string[i];
    }
    buffer[index++] = '"';
    buffer[index] = '\0';
    return buffer;
}

void StringHelper::CellIndex::setX(size_t x) {
    this->x = x;
}

void StringHelper::CellIndex::setY(size_t y) {
   this->y = y;
}

StringHelper::CellIndex::CellIndex(size_t x, size_t y) {
    setX(x);
    setY(y);
}

StringHelper::CellIndex::CellIndex(): x(0), y(0) {}
