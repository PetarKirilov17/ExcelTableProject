//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_PRINTCOMMAND_H
#define EXCELTABLEPROJECT_PRINTCOMMAND_H

#include "BaseCommand.h"

class PrintCommand : public BaseCommand{
public:
    void execute(SharedPointer<ExcelTable> &table, MyString &fileOfTable) override;
    SharedPointer<BaseCommand> clone() const override;
};

#endif //EXCELTABLEPROJECT_PRINTCOMMAND_H
