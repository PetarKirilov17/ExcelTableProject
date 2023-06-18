//
// Created by Petar on 18.6.2023 г..
//

#include "CommandFactory.h"
#include "ExitCommand.h"
#include "EditTableCommand.h"
#include "PrintCommand.h"
#include "SaveAsTableCommand.h"
#include "CloseTableCommand.h"
#include "SaveTableCommand.h"
#include "OpenTableCommand.h"
#include "WrongCommand.h"

CommandFactory *CommandFactory::instance = nullptr;

CommandFactory *CommandFactory::getInstance() {
    if (instance == nullptr) {
        instance = new CommandFactory();
    }
    return instance;
}

SharedPointer<BaseCommand> CommandFactory::createCommand() {
    std::cout << "Insert command: ";
    char command;
    std::cin >> command;
    std::cin.ignore();
    switch (command) {
        case '1':
            return new OpenTableCommand();
        case '2':
            return new CloseTableCommand();
        case '3':
            return new SaveTableCommand();
        case '4':
            return new SaveAsTableCommand();
        case '5':
            return new PrintCommand();
        case '6':
            return new EditTableCommand();
        case '7':
            return new ExitCommand();
        default:
            return new WrongCommand();
    }
}

void CommandFactory::freeInstance() {
    delete instance;
    instance = nullptr;
}