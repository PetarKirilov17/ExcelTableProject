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
    Row() = default;

    explicit Row(const MyVector<SharedPointer<BaseCell>> & cells);
    explicit Row(MyVector<SharedPointer<BaseCell>>&& cells);
    Row(const Row& other);
    Row& operator=(const Row& other);
    Row(Row&& other) noexcept;
    Row& operator=(Row&& other) noexcept;
    ~Row();

    size_t getCountOfCellsInRow() const;
    void addCell(const SharedPointer<BaseCell>& newCell);
    void setCell(size_t colIndex, const SharedPointer<BaseCell>& newCell);
    const BaseCell& getCellByIndex(size_t index) const;
    void printRow(const MyVector<size_t>& columnSizes) const;
    void writeRowToFile(std::ostream &os) const;
    void fillEmptyCells(size_t count);
    const SharedPointer<BaseCell> getCell(size_t colIndex) const;

private:
    void copyFrom(const Row& other);
    void moveFrom(Row&& other);
    void free();
};

#endif //EXCELTABLEPROJECT_ROW_H
