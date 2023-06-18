//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_OPENTABLECOMMAND_H
#define EXCELTABLEPROJECT_OPENTABLECOMMAND_H

#include "BaseCommand.h"

class OpenTableCommand : public BaseCommand{
private:
    SharedPointer<ExcelTable>& table;
    MyString& fileOfTable;
public:
    OpenTableCommand(SharedPointer<ExcelTable>& table, MyString& fileOfTable);
    SharedPointer<BaseCommand> clone() const override;
    void execute() override;
};

#endif //EXCELTABLEPROJECT_OPENTABLECOMMAND_H
