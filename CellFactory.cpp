//
// Created by Petar on 12.6.2023 г..
//

#include "CellFactory.h"
#include "Cells/IntegerCell.h"
#include "Cells/DoubleCell.h"
#include "Cells/StringCell.h"
#include "Cells/FormulaCell.h"
#include "stringHelperFunctions.h"

CellFactory* CellFactory::instance = nullptr;

CellFactory *CellFactory::getInstance() {
    if(!instance){
        instance = new CellFactory();
    }
    return instance;
}

void CellFactory::freeInstance() {
    delete instance;
    instance = nullptr;
}

SharedPointer<BaseCell>CellFactory::createCell(const MyString &cellData) {
    // here is the extraction of the cell data and creating the proper cell
    int integerResult = 0;
    if(StringHelper::tryParseToInt(cellData, integerResult)){
        return new IntegerCell(integerResult);
    }
    double doubleResult = 0.0;
    if(StringHelper::tryParseToDouble(cellData, doubleResult)){
        return new DoubleCell(doubleResult);
    }
    MyString stringResult;
    if(StringHelper::tryParseToString(cellData, stringResult)){
        return new StringCell(stringResult);
    }
    if(StringHelper::isFormulaCell(cellData)){
        return new FormulaCell(cellData); // initialize formula cell with raw data
    }
    throw std::invalid_argument("Wrong format of the table");
}

