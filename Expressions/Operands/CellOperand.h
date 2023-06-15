//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_CELLOPERAND_H
#define EXCELTABLEPROJECT_CELLOPERAND_H

#include "Operand.h"
#include "../../Cells/BaseCell.h"

class CellOperand : public Operand{
private:
    SharedPointer<BaseCell> cellPtr;
public:
    CellOperand(SharedPointer<BaseCell> cellPtr);
    virtual SharedPointer<BaseUnit> clone() const override;
    double getValue() const override;
};

#endif //EXCELTABLEPROJECT_CELLOPERAND_H
