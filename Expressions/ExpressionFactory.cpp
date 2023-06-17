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

ExpressionFactory* ExpressionFactory::instance = nullptr;

ExpressionFactory* ExpressionFactory::getInstance() {
    // TODO: mutex lock!
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
    size_t referredCellsIndex = 0;
    // we start from one because we skip the '='
    int i = 1;
    for (; i < stringExpr.length(); ++i) {
        char currentSymbol = stringExpr[i];
        if(!StringHelper::isDigit(currentSymbol) && !StringHelper::isOperator(currentSymbol) && currentSymbol != 'R'){
            continue;
        }
        if(StringHelper::isDigit(currentSymbol)){
            MyString numberExpr = StringHelper::extractNumberFromFormula(stringExpr, i, i);
            int intnumber = 0;
            double doubleNumber = 0.0;
            if(StringHelper::tryParseToInt(numberExpr, intnumber)){
                units.pushBack(new NumberOperand(intnumber));
            }else if(StringHelper::tryParseToDouble(numberExpr, doubleNumber)){
                units.pushBack(new NumberOperand(doubleNumber));
            }
        }else if(StringHelper::isOperator(currentSymbol)){
            switch (currentSymbol) {
                case PLUS_SIGN:
                    units.pushBack(new PlusOperator());
                    break;
                case MINUS_SIGN:
                    units.pushBack(new MinusOperator());
                    break;
                case MULTIPLY_SIGN:
                    units.pushBack(new MultiplyOperator());
                    break;
                case DIVISION_SIGN:
                    units.pushBack(new DivisionOperator());
                    break;
                case POW_SIGN:
                    units.pushBack(new PowOperator());
                    break;
                default:
                    break;
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
    return units;
}
