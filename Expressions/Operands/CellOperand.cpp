//
// Created by Petar on 15.6.2023 г..
//

#include "CellOperand.h"

SharedPointer<BaseUnit> CellOperand::clone() const {
    SharedPointer<BaseUnit>ptr(new CellOperand(*this));
    return ptr;
}

CellOperand::CellOperand(SharedPointer<BaseCell> cellPtr) : cellPtr(cellPtr){}

double CellOperand::getValue() const {
    return cellPtr->getFormulaValue();
}
