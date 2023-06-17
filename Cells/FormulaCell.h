//
// Created by Petar on 13.5.2023 г..
//

#ifndef EXCELTABLEPROJECT_FORMULACELL_H
#define EXCELTABLEPROJECT_FORMULACELL_H
#include "BaseCell.h"
#include "../Utils/SharedPointer.hpp"
#include "../Utils/MyVector.hpp"
#include "../stringHelperFunctions.h"
#include "../Expressions/BaseUnit.h"

class FormulaCell : public BaseCell{
private:
    MyString stringValue;
    MyVector<SharedPointer<BaseUnit>> expr;
    double evaluateExpression() const;
public:
    FormulaCell(const MyString& stringValue);
    void print(std::ostream &os) const override;
    BaseCell * clone() const override;
    int getWidth() const override;
    double getFormulaValue() const override;
    MyVector<StringHelper::CellIndex> getReferredIndexes();
    void fillTheReferredCells(const MyVector<SharedPointer<BaseCell>>& refs);
};

#endif //EXCELTABLEPROJECT_FORMULACELL_H
