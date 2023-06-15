//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_DIVISIONOPERATOR_H
#define EXCELTABLEPROJECT_DIVISIONOPERATOR_H

#include "Operator.h"

class DivisionOperator : public Operator{
public:
    SharedPointer<BaseUnit> clone() const override;
    double evaluate(double leftOperator, double rightOperator) const override;
};

#endif //EXCELTABLEPROJECT_DIVISIONOPERATOR_H
