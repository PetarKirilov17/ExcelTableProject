//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_OPENTABLECOMMAND_H
#define EXCELTABLEPROJECT_OPENTABLECOMMAND_H

#include "BaseCommand.h"

class OpenTableCommand : public BaseCommand{
public:
    SharedPointer<BaseCommand> clone() const override;
    void execute(SharedPointer<ExcelTable> &table, MyString &fileOfTable) override;
};

#endif //EXCELTABLEPROJECT_OPENTABLECOMMAND_H
