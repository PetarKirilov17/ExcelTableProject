//
// Created by Petar on 13.5.2023 г..
//

#include "StringCell.h"
#include "../stringHelperFunctions.h"

StringCell::StringCell(const MyString &stringInCell) {
    cellData = stringInCell;
}

void StringCell::print(std::ostream &os) const {
    os << cellData;
}

double StringCell::getFormulaValue() const {
    double doubleRes = 0.0;
    int intRes = 0;
    if(StringHelper::tryParseToDouble(cellData, doubleRes)){
        return doubleRes;
    }
    if(StringHelper::tryParseToInt(cellData,intRes)){
        return intRes;
    }
    return 0.0; // default
}

BaseCell *StringCell::clone() const {
    BaseCell* newCell = new StringCell(*this);
    return newCell;
}

int StringCell::getWidth() const {
    return cellData.length();
}

void StringCell::writeInFile(std::ostream &os) const {
    os << StringHelper::convertStringCellForOutput(cellData);
}

