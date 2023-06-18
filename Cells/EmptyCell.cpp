//
// Created by Petar on 18.6.2023 г..
//

#include "EmptyCell.h"

BaseCell *EmptyCell::clone() const {
    BaseCell* newCell = new EmptyCell(*this);
    return newCell;
}

int EmptyCell::getWidth() const {
    return 0;
}

double EmptyCell::getFormulaValue() const {
    return 0;
}

void EmptyCell::writeInFile(std::ostream &os) const {
    os << "";
}

void EmptyCell::print(std::ostream &os) const {
    os << "";
}
