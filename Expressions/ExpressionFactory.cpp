//
// Created by Petar on 15.6.2023 г..
//

#include "ExpressionFactory.h"
#include "../stringHelperFunctions.h"
#include "Operands/NumberOperand.h"
#include "../consts.h"
#include "Operators/PlusOperator.h"
#include "Operators/MinusOperator.h"
#include "Operators/MultiplyOperator.h"
#include "Operators/DivisionOperator.h"
#include "Operators/PowOperator.h"
#include "Operands/CellOperand.h"
#include "../Utils/MyStack.hpp"

ExpressionFactory* ExpressionFactory::instance = nullptr;

ExpressionFactory* ExpressionFactory::getInstance() {
    if (!instance) {
        instance = new ExpressionFactory();
    }
    return instance;
}

void ExpressionFactory::freeInstance() {
    delete instance;
    instance = nullptr;
}

MyVector<SharedPointer<BaseUnit>> ExpressionFactory::createExpression(const MyString &stringExpr,
                                                                      const MyVector<SharedPointer<BaseCell>> &referredCells) {
    MyVector<SharedPointer<BaseUnit>> units;
    MyStack<Operator*> operatorsStack;
    size_t referredCellsIndex = 0;
    // we start from one because we skip the '='
    int i = 1;
    for (; i < stringExpr.length(); ++i) {
        char currentSymbol = stringExpr[i];
        if(!StringHelper::isDigit(currentSymbol) && !StringHelper::isOperator(currentSymbol) && currentSymbol != 'R'){
            continue;
        }
        // parse and add number
        if(StringHelper::isDigit(currentSymbol)){
            MyString numberExpr = StringHelper::extractNumberFromFormula(stringExpr, i, i);
            int intnumber = 0;
            double doubleNumber = 0.0;
            if(StringHelper::tryParseToInt(numberExpr, intnumber)){
                units.pushBack(new NumberOperand(intnumber));
            }else if(StringHelper::tryParseToDouble(numberExpr, doubleNumber)){
                units.pushBack(new NumberOperand(doubleNumber));
            }
        }
        else if(StringHelper::isOperator(currentSymbol)){
            Operator* op = createOperator(currentSymbol);

            while (true){
                if(operatorsStack.isEmpty()){
                    operatorsStack.push(op);
                    break;
                }
                if(op->getPriority() > operatorsStack.peek()->getPriority()){
                    operatorsStack.push(op);
                    break;
                }
                if(!operatorsStack.isEmpty() && operatorsStack.peek()->getPriority() > op->getPriority()){
                    units.pushBack(operatorsStack.peek());
                    operatorsStack.pop();
                }
                if(!operatorsStack.isEmpty() && operatorsStack.peek()->getPriority() == op->getPriority()){
                    units.pushBack(operatorsStack.peek());
                    operatorsStack.pop();
                    operatorsStack.push(op);
                    break;
                }
            }

        }
        // start of cell reference
        else if(currentSymbol == 'R'){
            // here we are sure that referredCells contains the pointers to the cells
            units.pushBack(new CellOperand(referredCells[referredCellsIndex++]));
            // skip the row index
            while (stringExpr[i] != 'C'){
                i++;
            }
            // stringExpr[i] = 'C' -> skip the C
            i++;
            // skip the col index
            while (i < stringExpr.length() && StringHelper::isDigit(stringExpr[i])){
                i++;
            }
            i--; // because we have moved one index behind the last digit of the col index
        }
    }
    while (!operatorsStack.isEmpty()){
        units.pushBack(operatorsStack.peek());
        operatorsStack.pop();
    }
    return units;
}

Operator* ExpressionFactory::createOperator(char operatorSymbol) {
    switch (operatorSymbol) {
        case PLUS_SIGN:
           return new PlusOperator();
       case MINUS_SIGN:
           return new MinusOperator();
        case MULTIPLY_SIGN:
            return new MultiplyOperator();
        case DIVISION_SIGN:
            return new DivisionOperator();
        case POW_SIGN:
            return new PowOperator();
        default:
            throw std::invalid_argument("Error! Wrong operator");
    }
}
