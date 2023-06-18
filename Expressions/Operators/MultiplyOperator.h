//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_MULTIPLYOPERATOR_H
#define EXCELTABLEPROJECT_MULTIPLYOPERATOR_H

#include "Operator.h"

class MultiplyOperator : public Operator{
public:
    int getPriority() const override;
    SharedPointer<BaseUnit> clone() const override;
    double evaluate(double leftOperator, double rightOperator) const override;
};

#endif //EXCELTABLEPROJECT_MULTIPLYOPERATOR_H
