//
// Created by Petar on 18.6.2023 г..
//

#include "ExcelTableMenu.h"
#include "Commands/CommandFactory.h"

void ExcelTableMenu::printTheUserMenu() const {
    std::cout << "Choose option: " << std::endl;
    std::cout << "1. Open Table" << std::endl;
    std::cout << "2. Close Table" << std::endl;
    std::cout << "3. Save Table" << std::endl;
    std::cout << "4. Save Table As" << std::endl;
    std::cout << "5. Print Table" << std::endl;
    std::cout << "6. Edit Cell" << std::endl;
    std::cout << "7. Exit" << std::endl;
}

void ExcelTableMenu::processTheProgram() {
    CommandFactory* commandFactory = CommandFactory::getInstance();
    while(true){
        printTheUserMenu();
        SharedPointer<BaseCommand> command = commandFactory->createCommand();
        command->execute(this->table, this->tableFileName);
    }
}
