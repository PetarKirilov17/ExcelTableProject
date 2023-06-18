//
// Created by Petar on 18.6.2023 г..
//

#include "SaveTableCommand.h"

SharedPointer<BaseCommand> SaveTableCommand::clone() const {
    return SharedPointer<BaseCommand>(new SaveTableCommand(*this));
}

void SaveTableCommand::execute(SharedPointer<ExcelTable> &table, MyString &fileOfTable) {
    if(validateTable(table)){
        try {
            table->writeTableToFile(fileOfTable);
        }
        catch (std::exception& exc){
            std::cout << exc.what();
        }
    }
}
