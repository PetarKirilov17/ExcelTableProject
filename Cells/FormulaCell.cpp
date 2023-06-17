//
// Created by Petar on 13.5.2023 г..
//

#include "FormulaCell.h"
#include "../Expressions/ExpressionFactory.h"
#include "../Utils/MyStack.hpp"
#include "../Expressions/Operators/Operator.h"
#include "../Expressions/Operands/Operand.h"

BaseCell *FormulaCell::clone() const {
    BaseCell* newCell = new FormulaCell(*this);
    return newCell;
}

void FormulaCell::print(std::ostream &os) const {
    os << getFormulaValue();
}

double FormulaCell::getFormulaValue() const {
    return evaluateExpression();
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
    ExpressionFactory* fc = ExpressionFactory::getInstance();
    this->expr = fc->createExpression(stringValue, refs);
    ExpressionFactory::freeInstance();
}

double FormulaCell::evaluateExpression() const {
    double a;
    double b;
    MyStack<double> stack;
    for (int i = 0; i < expr.getSize(); ++i) {
        if(expr[i]->isOperator()){
            a = stack.peek();
            stack.pop();
            b = stack.peek();
            stack.pop();
            Operator* op = dynamic_cast<Operator*>(expr[i].get());
            stack.push(op->evaluate(a, b));
        }
        else{ // Operand
            Operand* operand = dynamic_cast<Operand*>(expr[i].get());
            stack.push(operand->getValue());
        }
    }
    return stack.peek();
}

int FormulaCell::getWidth() const {
    return StringHelper::findLength(getFormulaValue());
}
