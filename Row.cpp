//
// Created by Petar on 27.5.2023 г..
//
#include "Row.h"
#include "stringHelperFunctions.h"
#include "consts.h"
#include "Cells/EmptyCell.h"


void Row::addCell(const SharedPointer<BaseCell>& newCell) {
    cells.pushBack(newCell);
}

size_t Row::getCountOfCellsInRow() const {
    return this->cells.getSize();
}

const BaseCell &Row::getCellByIndex(size_t index) const {
    if(index >= cells.getSize())
        throw std::invalid_argument("Wrong index!");

    return *cells[index];
}

void Row::printRow(const MyVector<size_t> &columnSizes) const {
    std::cout << "|";
    size_t countOfCells = cells.getSize();
    for (int i = 0; i < countOfCells; ++i) {
        StringHelper::printSymbolNTimes(' ', MIN_COUNT_OF_ADDITIONAL_WHITESPACE / 2);
        size_t countOfPrintedSymbols = MIN_COUNT_OF_ADDITIONAL_WHITESPACE/2;
        cells[i]->print(std::cout);
        countOfPrintedSymbols+= cells[i]->getWidth();
        StringHelper::printSymbolNTimes(' ',columnSizes[i] - countOfPrintedSymbols);
        std::cout << "|";
    }
    for (int i = countOfCells; i < columnSizes.getSize(); ++i) {
        StringHelper::printSymbolNTimes(' ',columnSizes[i]);
        std::cout << "|";
    }
    std::cout << std::endl;
}

void Row::setCell(size_t colIndex, const SharedPointer<BaseCell> &newCell) {
    if(colIndex >= cells.getSize()){
        throw std::invalid_argument("Error! Invalid column index");
    }
    cells[colIndex] = newCell; // operator = of SharedPointer
}

void Row::writeRowToFile(std::ostream &os) const {
    for (int i = 0; i < cells.getSize() - 1; ++i) {
        cells[i]->writeInFile(os);
        os << ", ";
    }
    cells[cells.getSize() - 1]->writeInFile(os);
}

const SharedPointer<BaseCell> Row::getCell(size_t colIndex) const {
    if(colIndex >= cells.getSize()){
        throw std::invalid_argument("Error! Wrong columnIndex");
    }
    return cells[colIndex];
}

void Row::fillEmptyCells(size_t count) {
    for (int i = 0; i < count; ++i) {
        cells.pushBack(new EmptyCell());
    }
}

void Row::copyFrom(const Row &other) {
    for (int i = 0; i < other.cells.getSize(); ++i) {
        this->cells.pushBack(other.cells[i]->clone());
    }
}

void Row::moveFrom(Row &&other) {
    this->cells = std::move(other.cells);
}

void Row::free() {
    cells.clear();
}

Row::Row(const MyVector<SharedPointer<BaseCell>> &cells) : cells(cells.getSize()) {
    for (int i = 0; i < cells.getSize(); ++i) {
        this->cells.pushBack(cells[i]->clone());
    }
}

Row::Row(MyVector<SharedPointer<BaseCell>> &&cells) {
this->cells = std::move(cells);
}

Row::Row(const Row &other) : cells(other.cells.getSize()){
    copyFrom(other);
}

Row &Row::operator=(const Row &other) {
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

Row::Row(Row &&other) noexcept {
    moveFrom(std::move(other));
}

Row &Row::operator=(Row &&other) noexcept {
   if(this!= &other){
       free();
       moveFrom(std::move(other));
   }
    return *this;
}

Row::~Row() {
    free();
}
