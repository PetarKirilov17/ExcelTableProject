//
// Created by Petar on 15.6.2023 г..
//

#include "PowOperator.h"
#include "cmath"

SharedPointer<BaseUnit> PowOperator::clone() const {
    SharedPointer<BaseUnit> ptr(new PowOperator(*this));
    return ptr;
}
double PowOperator::evaluate(double leftOperator, double rightOperator) const {
    return pow(leftOperator, rightOperator);
}

int PowOperator::getPriority() const {
    return 3;
}
