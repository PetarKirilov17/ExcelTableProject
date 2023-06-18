//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_EMPTYCELL_H
#define EXCELTABLEPROJECT_EMPTYCELL_H

#include "BaseCell.h"

class EmptyCell : public BaseCell{
public:
    BaseCell * clone() const override;
    int getWidth() const override;
    double getFormulaValue() const override;
    void writeInFile(std::ostream &os) const override;
    void print(std::ostream &os) const override;
};

#endif //EXCELTABLEPROJECT_EMPTYCELL_H
