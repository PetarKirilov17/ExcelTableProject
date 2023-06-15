//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_NUMBEROPERAND_H
#define EXCELTABLEPROJECT_NUMBEROPERAND_H

#include "Operand.h"

class NumberOperand : public Operand{
private:
    double value;
public:
    NumberOperand(double value);
    double getValue() const override;
     SharedPointer<BaseUnit> clone() const override;
};

#endif //EXCELTABLEPROJECT_NUMBEROPERAND_H
