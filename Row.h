//
// Created by Petar on 27.5.2023 г..
//

#ifndef EXCELTABLEPROJECT_ROW_H
#define EXCELTABLEPROJECT_ROW_H
#include "Utils/MyVector.hpp"
#include "Cells/BaseCell.h"
#include "Utils/SharedPointer.hpp"

class Row{
private:
    MyVector<SharedPointer<BaseCell>> cells;
public:
    //TODO
    Row() = default;
    size_t getCountOfCellsInRow() const;
    void addCell(const SharedPointer<BaseCell>& newCell);
    const BaseCell& getCellByIndex(size_t index) const;
    void printRow(const MyVector<size_t>& columnSizes) const;
    // TODO : add functionality for changing(editing) cell by index
    ~Row();
};

#endif //EXCELTABLEPROJECT_ROW_H
