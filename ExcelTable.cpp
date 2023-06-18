//
// Created by Petar on 27.5.2023 г..
//
#include "ExcelTable.h"
#include "fstream"
#include "sstream"
#include "consts.h"
#include "stringHelperFunctions.h"
#include "CellFactory.h"

void ExcelTable::readTableFromFile(const MyString &filePath) {
    std::ifstream inFile(filePath.c_str(), std::ios::in);
    if(!inFile.is_open()){
        // TODO: check for better error
        throw std::invalid_argument("Error while opening the file!");
    }
    // TODO : is it ok to use static char array here

    char buffer[BUFFER_MAX_SIZE]{'\0'};

    while(!inFile.eof()){
        inFile.getline(buffer, BUFFER_MAX_SIZE);
        this->addRow(readRow(buffer));
    }
    fillTheFormulaCellsRefs();
    fillTheColumnSizes();
    CellFactory::freeInstance();
    inFile.close();
}

Row ExcelTable::readRow(const char *buffer) {
    std::stringstream rawData(buffer);
    Row currentRow;
    extractRow(rawData, currentRow);
    return currentRow;
}

void ExcelTable::extractRow(std::stringstream &rawData, Row &rowToChange) {
    CellFactory* factory = CellFactory::getInstance();
    char temporaryArray[BUFFER_MAX_SIZE] = {'\0'};
    rawData.getline(temporaryArray, BUFFER_MAX_SIZE, ',');
    while (!rawData.eof()){
        char trimmedArr[BUFFER_MAX_SIZE] = {'\0'};
        StringHelper::trimStr(temporaryArray, trimmedArr);
        SharedPointer<BaseCell> newCell = factory->createCell(trimmedArr);
        rowToChange.addCell(newCell); // TODO :: check
        FormulaCell* formulaCell = dynamic_cast<FormulaCell*>(newCell.get());
        if(formulaCell != nullptr){ // is it ok here
            tempFormulaCells.pushBack(formulaCell);
        }
        rawData.getline(temporaryArray, BUFFER_MAX_SIZE, ',');
    }

}

void ExcelTable::addRow(const Row &row) {
    this->rows.pushBack(row);
}

void ExcelTable::fillTheFormulaCellsRefs() {
    for (int i = 0; i < tempFormulaCells.getSize(); ++i) {
        MyVector<StringHelper::CellIndex> refIndexes = tempFormulaCells[i]->getReferredIndexes();
        MyVector<SharedPointer<BaseCell>> refs;
        for (int j = 0; j < refIndexes.getSize(); ++j) {
            SharedPointer<BaseCell>ptr(findCellByRowAndColIndexes(refIndexes[j].x, refIndexes[j].y).clone());
            refs.pushBack(std::move(ptr));
        }
        tempFormulaCells[i]->fillTheReferredCells(refs);
    }
}

// R1C6 - first row; sixth column -> rows[0].cells[5]
const BaseCell &ExcelTable::findCellByRowAndColIndexes(size_t rowIndex, size_t colIndex) {
    if(rowIndex - 1 >= rows.getSize())
        throw std::invalid_argument("Wrong row index!");

    Row& currentRow = rows[rowIndex - 1];
    size_t rowSize = currentRow.getCountOfCellsInRow();

    if(colIndex - 1 >= rowSize)
        throw std::invalid_argument("Wrong column index!");

    return currentRow.getCellByIndex(colIndex-1);
}

size_t ExcelTable::getMaxWidthForColumn(int columnIndex) const {
    size_t maxWidth = 0;
    for (int i = 0; i < this->rows.getSize(); ++i) {
        if(columnIndex >= this->rows[i].getCountOfCellsInRow())
            continue;
        size_t currentElementLength = this->rows[i].getCellByIndex(columnIndex).getWidth();
        if(currentElementLength > maxWidth){
            maxWidth = currentElementLength;
        }
    }
    return maxWidth;
}

void ExcelTable::fillTheColumnSizes() {
    size_t countOfCols = getCountOfColsInTable();
    for (int i = 0; i < countOfCols; ++i) {
        columnSizes.pushBack(getMaxWidthForColumn(i) + 2 * MIN_COUNT_OF_ADDITIONAL_WHITESPACE);
    }
}

size_t ExcelTable::getCountOfColsInTable() const {
    size_t maxCount = 0;
    for (int i = 0; i < rows.getSize(); ++i) {
        size_t currLength = rows[i].getCountOfCellsInRow();
        if(currLength > maxCount){
            maxCount = currLength;
        }
    }
    return maxCount;
}

void ExcelTable::printTable() const {
    for (int i = 0; i < rows.getSize(); ++i) {
        rows[i].printRow(columnSizes);
    }
}
