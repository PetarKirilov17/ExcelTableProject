//
// Created by Petar on 15.6.2023 г..
//

#include "MinusOperator.h"

double MinusOperator::evaluate(double leftOperator, double rightOperator) const {
    return leftOperator - rightOperator;
}

SharedPointer<BaseUnit> MinusOperator::clone() const {
    SharedPointer<BaseUnit> ptr(new MinusOperator(*this));
    return ptr;
}
