//
// Created by Petar on 18.6.2023 г..
//

#include "SaveAsTableCommand.h"
#include "../consts.h"

SaveAsTableCommand::SaveAsTableCommand(SharedPointer<ExcelTable> &table, MyString &fileOfTable) : table(table), fileOfTable(fileOfTable) {}

SharedPointer<BaseCommand> SaveAsTableCommand::clone() const {
    return SharedPointer<BaseCommand>(new SaveAsTableCommand(*this));
}

void SaveAsTableCommand::execute() {
    if(!validateTable(table)){
        return;
    }
    char buffer[BUFFER_MAX_SIZE]{'\0'};
    std::cout << "Enter file name of the file where you want to save the table: ";
    std::cin.getline(buffer, BUFFER_MAX_SIZE);
    try{
        table->writeTableToFile(buffer);
        fileOfTable = buffer;
    }catch (std::exception& exc){
        std::cout << exc.what() << std::endl;
    }
}

