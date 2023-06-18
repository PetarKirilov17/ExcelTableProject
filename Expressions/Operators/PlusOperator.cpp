//
// Created by Petar on 15.6.2023 г..
//
#include "PlusOperator.h"

double PlusOperator::evaluate(double leftOperator, double rightOperator) const {
    return leftOperator + rightOperator;
}

SharedPointer<BaseUnit> PlusOperator::clone() const {
    SharedPointer<BaseUnit> ptr(new PlusOperator(*this));
    return ptr;
}

int PlusOperator::getPriority() const {
    return 1;
}
