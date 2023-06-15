//
// Created by Petar on 13.5.2023 г..
//

#include "FormulaCell.h"

BaseCell *FormulaCell::clone() const {
    BaseCell* newCell = new FormulaCell(*this);
    return newCell;
}

void FormulaCell::print(std::ostream &os) const {

}

double FormulaCell::getFormulaValue() const {
    return 0;
}

MyVector<StringHelper::CellIndex> FormulaCell::getReferredIndexes() {
    MyVector<StringHelper::CellIndex> result;

    unsigned row = 0;
    unsigned col = 0;
    bool isParsingRow = false;
    bool isParsingCol = false;

    // we start from 1 because we skip the '='
    for (int i = 1; i < stringValue.length(); ++i) {
        char currentChar = stringValue[i];
        if(currentChar == 'R'){
            isParsingRow = true;
            isParsingCol = false;
            row = 0;
        }
        else if(currentChar == 'C'){
            isParsingRow = false;
            isParsingCol = true;
            col = 0;
        }
        else if(StringHelper::isDigit(currentChar)){
            if(isParsingRow){
                row = row * 10 + (currentChar - '0');
            }else if(isParsingCol){
                col = col * 10 + (currentChar - '0');
            }
        }
        else{
            if(isParsingRow || isParsingCol){
                StringHelper::CellIndex index(row, col);
                result.pushBack(std::move(index));
            }
            isParsingRow = false;
            isParsingCol = false;
        }
    }
    if(isParsingRow || isParsingCol){
        StringHelper::CellIndex index(row, col);
        result.pushBack(std::move(index));
    }
    return result;
}

FormulaCell::FormulaCell(const MyString &stringValue) {
    if(StringHelper::isFormulaCell(stringValue))
        this->stringValue = stringValue;
}

void FormulaCell::fillTheReferredCells(const MyVector<SharedPointer<BaseCell>> &refs) {
    //    Factory fc;
//    this->expr == fc.getExpr(string, refs);
//    this->referredCells = refs;
}
