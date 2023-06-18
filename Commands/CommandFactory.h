//
// Created by Petar on 18.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_COMMANDFACTORY_H
#define EXCELTABLEPROJECT_COMMANDFACTORY_H

#include "BaseCommand.h"

class CommandFactory{
private:
    static CommandFactory* instance;
    CommandFactory() = default;
public:
    CommandFactory(const CommandFactory&) = delete;
    CommandFactory& operator=(const CommandFactory&) = delete;

    static CommandFactory* getInstance();
    SharedPointer<BaseCommand> createCommand();
    static void freeInstance();
};

#endif //EXCELTABLEPROJECT_COMMANDFACTORY_H
