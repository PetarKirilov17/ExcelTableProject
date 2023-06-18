//
// Created by Petar on 18.6.2023 г..
//

#include "ExitCommand.h"
#include "../CellFactory.h"
#include "CommandFactory.h"

void ExitCommand::execute(SharedPointer<ExcelTable> &table, MyString &fileOfTable) {
    std::cout << "Exit!";
    CellFactory::freeInstance();
    CommandFactory::freeInstance();
    exit(0);
}

SharedPointer<BaseCommand> ExitCommand::clone() const {
    return SharedPointer<BaseCommand>(new ExitCommand(*this));
}
