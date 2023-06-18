//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_WRONGCOMMAND_H
#define EXCELTABLEPROJECT_WRONGCOMMAND_H

#include "BaseCommand.h"

class WrongCommand : public BaseCommand{
public:
    void execute() override;
    SharedPointer<BaseCommand> clone() const override;
};

#endif //EXCELTABLEPROJECT_WRONGCOMMAND_H
