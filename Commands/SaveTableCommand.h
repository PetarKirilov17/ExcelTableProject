//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_SAVETABLECOMMAND_H
#define EXCELTABLEPROJECT_SAVETABLECOMMAND_H

#include "BaseCommand.h"

class SaveTableCommand : public BaseCommand{
public:
    void execute(SharedPointer<ExcelTable> &table, MyString &fileOfTable) override;
    SharedPointer<BaseCommand> clone() const override;
};

#endif //EXCELTABLEPROJECT_SAVETABLECOMMAND_H
