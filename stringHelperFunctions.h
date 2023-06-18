//
// Created by Petar on 14.5.2023 г..
//

#ifndef EXCELTABLEPROJECT_STRINGHELPERFUNCTIONS_H
#define EXCELTABLEPROJECT_STRINGHELPERFUNCTIONS_H
#include "Utils/MyString.h"
#include "Utils/MyVector.hpp"

namespace StringHelper{
    struct CellIndex{
        size_t x;
        size_t y;
        CellIndex();
        CellIndex(size_t x, size_t y);
        void setX(size_t x);
        void setY(size_t y);
    };
    void trimStr(const char* src, char* dest);
    bool tryParseToInt(const MyString& string, int& result);
    bool tryParseToDouble(const MyString& string, double& result);
    bool tryParseToString(const MyString& inputString, MyString& result);
    bool isFormulaCell(const MyString& string);
    bool isEmptyCell(const MyString& string);
    int findLength(int number);
    int findLength(double number);
    void printSymbolNTimes(char symbol, size_t times);
    MyString extractNumberFromFormula(const MyString& stringExpr, int start, int& index);
    MyString convertStringCellForOutput(const MyString& string);
    bool isDigit(const char symbol);
    bool isOperator(const char symbol);

}




#endif //EXCELTABLEPROJECT_STRINGHELPERFUNCTIONS_H
