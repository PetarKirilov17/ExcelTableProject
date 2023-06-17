//
// Created by Petar on 13.5.2023 г..
//

#ifndef EXCELTABLEPROJECT_STRINGCELL_H
#define EXCELTABLEPROJECT_STRINGCELL_H
#include "BaseCell.h"

class StringCell : public BaseCell{
private:
    MyString cellData;
public:
    StringCell(const MyString& stringInCell);
    void print(std::ostream &os) const override;
    double getFormulaValue() const override;
    int getWidth() const override;
    BaseCell * clone() const override;
};

#endif //EXCELTABLEPROJECT_STRINGCELL_H
