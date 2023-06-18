//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_SAVETABLECOMMAND_H
#define EXCELTABLEPROJECT_SAVETABLECOMMAND_H

#include "BaseCommand.h"

class SaveTableCommand : public BaseCommand{
private:
    SharedPointer<ExcelTable>& table;
    MyString& fileOfTable;
public:
    SaveTableCommand(SharedPointer<ExcelTable> &table, MyString& fileOfTable);
    void execute() override;
    SharedPointer<BaseCommand> clone() const override;
};

#endif //EXCELTABLEPROJECT_SAVETABLECOMMAND_H
