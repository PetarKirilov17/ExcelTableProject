//
// Created by Petar on 12.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_CELLFACTORY_H
#define EXCELTABLEPROJECT_CELLFACTORY_H
#include "Cells/BaseCell.h"

class CellFactory{
private:
    static CellFactory* instance;
    CellFactory() = default;
public:
    CellFactory(const CellFactory& other) = delete;
    CellFactory& operator=(const CellFactory& other) = delete;

    static CellFactory* getInstance();
    static void freeInstance();
    BaseCell* createCell(const MyString& cellData);
};

#endif //EXCELTABLEPROJECT_CELLFACTORY_H
