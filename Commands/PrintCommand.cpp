//
// Created by Petar on 18.6.2023 г..
//

#include "PrintCommand.h"

void PrintCommand::execute() {
    if(!validateTable(table)){
        return;
    }
    std::cout << std::endl;
    table->printTable();
}

SharedPointer<BaseCommand> PrintCommand::clone() const {
    return SharedPointer<BaseCommand>(new PrintCommand(*this));
}

PrintCommand::PrintCommand(SharedPointer<ExcelTable> &table) : table(table) {}
