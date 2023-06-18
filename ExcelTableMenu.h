//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_EXCELTABLEMENU_H
#define EXCELTABLEPROJECT_EXCELTABLEMENU_H

#include "Utils/SharedPointer.hpp"
#include "ExcelTable.h"

class ExcelTableMenu{
private:
    SharedPointer<ExcelTable> table;
    MyString tableFileName;

public:
    void printTheUserMenu() const;
    void processTheProgram();
};

#endif //EXCELTABLEPROJECT_EXCELTABLEMENU_H
