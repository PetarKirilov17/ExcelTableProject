//
// Created by Petar on 27.5.2023 г..
//

#ifndef EXCELTABLEPROJECT_EXCELTABLE_H
#define EXCELTABLEPROJECT_EXCELTABLE_H
#include "Utils/MyVector.hpp"
#include "Row.h"
#include "Utils/SharedPointer.hpp"
#include "Cells/FormulaCell.h"
class ExcelTable{
private:
    MyVector<Row> rows;
    MyVector<SharedPointer<FormulaCell>> tempFormulaCells;
    Row readRow(const char* buffer);
    void extractRow(std::stringstream& rawData, Row& rowToChange);
    void fillTheFormulaCellsRefs();
    const BaseCell& findCellByRowAndColIndexes(size_t rowIndex, size_t colIndex);

public:
    ExcelTable() = default;
    void readTableFromFile(const MyString& filePath);
    void addRow(const Row& row);
    void printTable() const;
};

#endif //EXCELTABLEPROJECT_EXCELTABLE_H
