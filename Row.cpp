//
// Created by Petar on 27.5.2023 г..
//
#include "Row.h"

Row::~Row() {
    // TODO :: I think it is not needed
}

void Row::addCell(const BaseCell &newCell) {
    SharedPointer<BaseCell>ptr(newCell.clone());
    cells.pushBack(std::move(ptr));
}

size_t Row::getCountOfCellsInRow() const {
    return this->cells.getSize();
}

const BaseCell &Row::getCellByIndex(size_t index) const {
    if(index >= cells.getSize())
        throw std::invalid_argument("Wrong index!");

    return *cells[index];
}
