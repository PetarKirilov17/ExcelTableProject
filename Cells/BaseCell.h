//
// Created by Petar on 13.5.2023 г..
//

#ifndef EXCELTABLEPROJECT_BASECELL_H
#define EXCELTABLEPROJECT_BASECELL_H
#include "fstream"
#include "../Utils/MyString.h"

class BaseCell{
public:
    virtual void print(std::ostream& os) const = 0;
    virtual double getFormulaValue() const = 0;
    virtual BaseCell* clone() const = 0;
    virtual ~BaseCell() = default;
};

#endif //EXCELTABLEPROJECT_BASECELL_H