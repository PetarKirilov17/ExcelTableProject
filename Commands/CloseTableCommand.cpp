//
// Created by Petar on 18.6.2023 г..
//

#include "CloseTableCommand.h"

SharedPointer<BaseCommand> CloseTableCommand::clone() const {
    return SharedPointer<BaseCommand>(new CloseTableCommand(*this));
}

void CloseTableCommand::execute(SharedPointer<ExcelTable> &table, MyString &fileOfTable) {
    if(validateTable(table)){
        table = nullptr; // empty the table pointer
        fileOfTable = "\0"; // empty the file name of the table
    }
}
