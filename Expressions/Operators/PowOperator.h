//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_POWOPERATOR_H
#define EXCELTABLEPROJECT_POWOPERATOR_H

#include "Operator.h"

class PowOperator : public Operator{
public:
    SharedPointer<BaseUnit> clone() const override;
    double evaluate(double leftOperator, double rightOperator) const override;
};

#endif //EXCELTABLEPROJECT_POWOPERATOR_H
