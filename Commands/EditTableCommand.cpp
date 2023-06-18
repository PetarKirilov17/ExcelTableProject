//
// Created by Petar on 18.6.2023 г..
//

#include "EditTableCommand.h"
#include "../consts.h"
#include "../CellFactory.h"

SharedPointer<BaseCommand> EditTableCommand::clone() const {
    return SharedPointer<BaseCommand>(new EditTableCommand(*this));
}

void EditTableCommand::execute(SharedPointer<ExcelTable> &table, MyString &fileOfTable) {
    if(!validateTable(table))
        return;

    int rowToChange = 0;
    int colToChange = 0;
    char buffer[BUFFER_MAX_SIZE]{'\0'};
    std::cout << "Insert cell row: ";
    std::cin >> rowToChange;
    std::cout << "Insert the cell column: ";
    std::cin >> colToChange;
    std::cout << "Insert the value you want to put in the cell: ";
    std::cin.ignore();
    std::cin.getline(buffer, BUFFER_MAX_SIZE);
    CellFactory* fc = CellFactory::getInstance();
    try{
        SharedPointer<BaseCell> newCell = fc->createCell(buffer);
        table->setCell(rowToChange - 1, colToChange - 1, newCell);

    }catch(std::exception& exc){
        std::cout << exc.what();
    }
}
