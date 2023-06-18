//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_MINUSOPERATOR_H
#define EXCELTABLEPROJECT_MINUSOPERATOR_H

#include "Operator.h"

class MinusOperator : public Operator{
public:
    int getPriority() const override;
    double evaluate(double leftOperator, double rightOperator) const override;
    SharedPointer<BaseUnit> clone() const override;
};

#endif //EXCELTABLEPROJECT_MINUSOPERATOR_H
