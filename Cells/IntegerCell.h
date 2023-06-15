//
// Created by Petar on 13.5.2023 г..
//

#ifndef EXCELTABLEPROJECT_INTEGERCELL_H
#define EXCELTABLEPROJECT_INTEGERCELL_H
#include "BaseCell.h"

class IntegerCell : public BaseCell{
private:
    int cellData = 0;
public:
    explicit IntegerCell(int numberInCell);
    void print(std::ostream& os) const override;
    double getFormulaValue() const override;
    BaseCell * clone() const override;

private:
    void setCellData(int numberInCell);
};

#endif //EXCELTABLEPROJECT_INTEGERCELL_H
