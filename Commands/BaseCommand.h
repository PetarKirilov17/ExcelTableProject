//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_BASECOMMAND_H
#define EXCELTABLEPROJECT_BASECOMMAND_H

#include "../Utils/SharedPointer.hpp"
#include "../ExcelTable.h"

class BaseCommand{
public:
    bool validateTable(const SharedPointer<ExcelTable>& table);
    virtual void execute() = 0;
    virtual SharedPointer<BaseCommand> clone() const = 0;
    virtual ~BaseCommand() = default;
};

#endif //EXCELTABLEPROJECT_BASECOMMAND_H
