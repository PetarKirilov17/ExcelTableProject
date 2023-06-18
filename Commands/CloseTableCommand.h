//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_CLOSETABLECOMMAND_H
#define EXCELTABLEPROJECT_CLOSETABLECOMMAND_H

#include "BaseCommand.h"

class CloseTableCommand : public BaseCommand{
private:
    SharedPointer<ExcelTable>& table;
    MyString& fileOfTable;
public:
    CloseTableCommand(SharedPointer<ExcelTable>&table, MyString& fileOfTable);
    SharedPointer<BaseCommand> clone() const override;
    void execute() override;
};

#endif //EXCELTABLEPROJECT_CLOSETABLECOMMAND_H
