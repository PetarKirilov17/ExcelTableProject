//
// Created by Petar on 13.5.2023 г..
//

#include "DoubleCell.h"
#include "../stringHelperFunctions.h"

void DoubleCell::setCellData(double numberInCell) {
    //TODO: add validations if needed
    this->cellData = numberInCell;
}

DoubleCell::DoubleCell(double numberInCell) {
    setCellData(numberInCell);
}

void DoubleCell::print(std::ostream &os) const {
    os << cellData;
}

double DoubleCell::getFormulaValue() const {
    return cellData;
}

BaseCell *DoubleCell::clone() const {
    BaseCell* newCell = new DoubleCell(*this);
    return newCell;
}

int DoubleCell::getWidth() const {
    return StringHelper::findLength(cellData);
}

void DoubleCell::writeInFile(std::ostream &os) const {
    os << cellData;
}


