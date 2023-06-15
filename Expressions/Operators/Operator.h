//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_OPERATOR_H
#define EXCELTABLEPROJECT_OPERATOR_H

#include "../BaseUnit.h"

class Operator : public BaseUnit{
public:
    virtual double evaluate(double leftOperator, double rightOperator) const = 0;
    bool isOperator() const override;
};

#endif //EXCELTABLEPROJECT_OPERATOR_H
