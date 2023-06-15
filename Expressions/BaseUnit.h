//
// Created by Petar on 15.6.2023 г..
//

#ifndef EXCELTABLEPROJECT_BASEUNIT_H
#define EXCELTABLEPROJECT_BASEUNIT_H

#include "../Utils/SharedPointer.hpp"

class BaseUnit{
public:
    virtual bool isOperator() const = 0;
    virtual SharedPointer<BaseUnit> clone() const = 0;
    virtual ~BaseUnit() = default;
};

#endif //EXCELTABLEPROJECT_BASEUNIT_H
