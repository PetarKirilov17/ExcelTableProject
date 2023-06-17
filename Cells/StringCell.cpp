//
// Created by Petar on 13.5.2023 г..
//

#include "StringCell.h"

StringCell::StringCell(const MyString &stringInCell) {
    cellData = stringInCell;
}

void StringCell::print(std::ostream &os) const {
    os << cellData;
}

double StringCell::getFormulaValue() const {
    //TODO :: extract number from string
    return 0.0;
}

BaseCell *StringCell::clone() const {
    BaseCell* newCell = new StringCell(*this);
    return newCell;
}

int StringCell::getWidth() const {
    return cellData.length();
}

