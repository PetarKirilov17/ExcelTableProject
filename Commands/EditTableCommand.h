//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_EDITTABLECOMMAND_H
#define EXCELTABLEPROJECT_EDITTABLECOMMAND_H

#include "BaseCommand.h"

class EditTableCommand : public BaseCommand{
private:
    SharedPointer<ExcelTable>& table;
public:
    EditTableCommand(SharedPointer<ExcelTable>& table);
    void execute() override;
    SharedPointer<BaseCommand> clone() const override;
};

#endif //EXCELTABLEPROJECT_EDITTABLECOMMAND_H
