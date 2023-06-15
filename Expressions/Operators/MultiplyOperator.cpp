//
// Created by Petar on 15.6.2023 г..
//

#include "MultiplyOperator.h"

SharedPointer<BaseUnit> MultiplyOperator::clone() const {
    SharedPointer<BaseUnit> ptr(new MultiplyOperator(*this));
    return ptr;
}

double MultiplyOperator::evaluate(double leftOperator, double rightOperator) const {
    return leftOperator * rightOperator;
}
