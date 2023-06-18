//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_EXITCOMMAND_H
#define EXCELTABLEPROJECT_EXITCOMMAND_H

#include "BaseCommand.h"

class ExitCommand : public BaseCommand{
public:
    void execute() override;
    SharedPointer<BaseCommand> clone() const override;
};

#endif //EXCELTABLEPROJECT_EXITCOMMAND_H
