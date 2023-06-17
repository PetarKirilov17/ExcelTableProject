//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_EXPRESSIONFACTORY_H
#define EXCELTABLEPROJECT_EXPRESSIONFACTORY_H

#include "../Utils/SharedPointer.hpp"
#include "BaseUnit.h"
#include "../Utils/MyString.h"
#include "../Utils/MyVector.hpp"
#include "../Cells/BaseCell.h"

class ExpressionFactory{
private:
    static ExpressionFactory* instance;
    ExpressionFactory() = default;
public:
    ExpressionFactory(const ExpressionFactory& other) = delete;
    ExpressionFactory& operator=(const ExpressionFactory& other) = delete;

    static ExpressionFactory* getInstance();
    static void freeInstance();
    MyVector<SharedPointer<BaseUnit>> createExpression(const MyString& stringExpr,
                                                       const MyVector<SharedPointer<BaseCell>>& referredCells);
};

#endif //EXCELTABLEPROJECT_EXPRESSIONFACTORY_H
