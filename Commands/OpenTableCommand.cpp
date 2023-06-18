//
// Created by Petar on 18.6.2023 г..
//

#include "OpenTableCommand.h"
#include "../consts.h"

SharedPointer<BaseCommand> OpenTableCommand::clone() const {
    return SharedPointer<BaseCommand>(new OpenTableCommand(*this));
}

OpenTableCommand::OpenTableCommand(SharedPointer<ExcelTable> &table, MyString &fileOfTable) : table(table), fileOfTable(fileOfTable) {}

void OpenTableCommand::execute() {
    char buffer[BUFFER_MAX_SIZE]{'\0'};
    std::cout << "Insert the file from which to read the table: ";
    std::cin.getline(buffer, BUFFER_MAX_SIZE);

    table = new ExcelTable();
    fileOfTable = buffer;

    try{
        table->readTableFromFile(fileOfTable);
    }
    catch (std::exception& exc){
        std::cout << exc.what() << std::endl;
    }
}
