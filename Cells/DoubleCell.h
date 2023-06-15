//
// Created by Petar on 13.5.2023 г..
//

#ifndef EXCELTABLEPROJECT_DOUBLECELL_H
#define EXCELTABLEPROJECT_DOUBLECELL_H
#include "BaseCell.h"

class DoubleCell : public BaseCell{
private:
    double cellData = 0.0;
public:
    explicit DoubleCell(double numberInCell);
    void print(std::ostream &os) const override;
    double getFormulaValue() const override;
    BaseCell * clone() const override;

private:
    void setCellData(double numberInCell);
};

#endif //EXCELTABLEPROJECT_DOUBLECELL_H
