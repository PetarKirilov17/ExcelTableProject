//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_OPERAND_H
#define EXCELTABLEPROJECT_OPERAND_H
#include "../BaseUnit.h"

class Operand : public BaseUnit{
public:
   virtual double getValue() const = 0;
    bool isOperator() const override;
};

#endif //EXCELTABLEPROJECT_OPERAND_H
