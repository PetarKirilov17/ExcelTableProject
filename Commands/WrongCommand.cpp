//
// Created by Petar on 18.6.2023 г..
//

#include "WrongCommand.h"

SharedPointer<BaseCommand> WrongCommand::clone() const {
    return SharedPointer<BaseCommand>(new WrongCommand(*this));
}

void WrongCommand::execute() {
    std::cout << "Wrong command! Please insert (1-7)" << std::endl;
}
