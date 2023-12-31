//
// Created by Petar on 13.5.2023 г..
//

#include "IntegerCell.h"
#include "../stringHelperFunctions.h"

void IntegerCell::print(std::ostream &os) const {
    os << cellData;
}

double IntegerCell::getFormulaValue() const {
    return (double)cellData;
}

void IntegerCell::setCellData(int numberInCell) {
    this->cellData = numberInCell;
}

IntegerCell::IntegerCell(int numberInCell) {
    setCellData(numberInCell);
}

BaseCell *IntegerCell::clone() const {
    BaseCell* newCell = new IntegerCell(*this);
    return newCell;
}

int IntegerCell::getWidth() const {
    return StringHelper::findLength(cellData);
}

void IntegerCell::writeInFile(std::ostream &os) const {
    os << cellData;
}
