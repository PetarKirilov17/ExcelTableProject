//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_PLUSOPERATOR_H
#define EXCELTABLEPROJECT_PLUSOPERATOR_H

#include "Operator.h"

class PlusOperator : public Operator{
public:
    double evaluate(double leftOperator, double rightOperator) const override;
    SharedPointer<BaseUnit> clone() const override;

};

#endif //EXCELTABLEPROJECT_PLUSOPERATOR_H
