//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_CLOSETABLECOMMAND_H
#define EXCELTABLEPROJECT_CLOSETABLECOMMAND_H

#include "BaseCommand.h"

class CloseTableCommand : public BaseCommand{
public:
    SharedPointer<BaseCommand> clone() const override;
    void execute(SharedPointer<ExcelTable> &table, MyString &fileOfTable) override;
};

#endif //EXCELTABLEPROJECT_CLOSETABLECOMMAND_H
