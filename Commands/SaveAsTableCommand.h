//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_SAVEASTABLECOMMAND_H
#define EXCELTABLEPROJECT_SAVEASTABLECOMMAND_H

#include "BaseCommand.h"

class SaveAsTableCommand : public BaseCommand{
private:
    SharedPointer<ExcelTable>& table;
    MyString& fileOfTable;
public:
    SaveAsTableCommand(SharedPointer<ExcelTable> &table, MyString &fileOfTable);
    SharedPointer<BaseCommand> clone() const override;
    void execute() override;
};

#endif //EXCELTABLEPROJECT_SAVEASTABLECOMMAND_H
