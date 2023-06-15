//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_EXPRESSIONFACTORY_H
#define EXCELTABLEPROJECT_EXPRESSIONFACTORY_H

#include "../Utils/SharedPointer.hpp"
#include "BaseUnit.h"
#include "../Utils/MyString.h"

class ExpressionFactory{
private:
    static ExpressionFactory* instance;
    ExpressionFactory();
public:
    ExpressionFactory(const ExpressionFactory& other) = delete;
    ExpressionFactory& operator=(const ExpressionFactory& other) = delete;
    ~ExpressionFactory();

    static ExpressionFactory* getInstance();
    static void freeInstance();
    SharedPointer<BaseUnit> createCell(const MyString& cellData);
};

#endif //EXCELTABLEPROJECT_EXPRESSIONFACTORY_H
