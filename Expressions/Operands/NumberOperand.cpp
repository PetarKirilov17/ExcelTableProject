//
// Created by Petar on 15.6.2023 г..
//

#include "NumberOperand.h"

SharedPointer<BaseUnit> NumberOperand::clone() const {
    SharedPointer<BaseUnit> ptr(new NumberOperand(*this));
    return ptr;
}

double NumberOperand::getValue() const {
    return this->value;
}

NumberOperand::NumberOperand(double value) {
    this->value  = value;
}
