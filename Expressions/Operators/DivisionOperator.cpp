//
// Created by Petar on 15.6.2023 г..
//

#include "DivisionOperator.h"

SharedPointer<BaseUnit> DivisionOperator::clone() const {
    SharedPointer<BaseUnit> ptr(new DivisionOperator(*this));
    return ptr;
}

double DivisionOperator::evaluate(double leftOperator, double rightOperator) const {
    if(rightOperator == 0){
        throw std::invalid_argument("Error! Cannot divide by zero");
    }
    return leftOperator / rightOperator;
}

int DivisionOperator::getPriority() const {
    return 2;
}
