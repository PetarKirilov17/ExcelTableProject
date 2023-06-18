//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_SAVEASTABLECOMMAND_H
#define EXCELTABLEPROJECT_SAVEASTABLECOMMAND_H

#include "BaseCommand.h"

class SaveAsTableCommand : public BaseCommand{
public:
    SharedPointer<BaseCommand> clone() const override;
    void execute(SharedPointer<ExcelTable> &table, MyString &fileOfTable) override;
};

#endif //EXCELTABLEPROJECT_SAVEASTABLECOMMAND_H
