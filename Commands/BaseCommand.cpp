//
// Created by Petar on 18.6.2023 г..
//
#include "BaseCommand.h"

bool BaseCommand::validateTable(const SharedPointer<ExcelTable> &table) {
    if(table.get() == nullptr){
        std::cout << "No loaded table!" << std::endl;
        return false;
    }
    return true;
}
