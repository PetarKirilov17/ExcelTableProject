//
// Created by Petar on 18.6.2023 г..
//

#include "SaveTableCommand.h"


SaveTableCommand::SaveTableCommand(SharedPointer<ExcelTable> &table, MyString& fileOfTable) : table(table), fileOfTable(fileOfTable) {}

SharedPointer<BaseCommand> SaveTableCommand::clone() const {
    return SharedPointer<BaseCommand>(new SaveTableCommand(*this));
}

void SaveTableCommand::execute() {
    if(validateTable(table)){
        try {
            table->writeTableToFile(fileOfTable);
        }
        catch (std::exception& exc){
            std::cout << exc.what();
        }
    }
}

