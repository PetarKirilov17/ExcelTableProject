//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_PRINTCOMMAND_H
#define EXCELTABLEPROJECT_PRINTCOMMAND_H

#include "BaseCommand.h"

class PrintCommand : public BaseCommand{
private:
    SharedPointer<ExcelTable>& table;
public:
    PrintCommand(SharedPointer<ExcelTable>& table);
    void execute() override;
    SharedPointer<BaseCommand> clone() const override;
};

#endif //EXCELTABLEPROJECT_PRINTCOMMAND_H
