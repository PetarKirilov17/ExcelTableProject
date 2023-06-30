//
// Created by Petar on 14.6.2023 г..
//

//https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2008/String%20and%20StringView/StringView.h
#ifndef EXCELTABLEPROJECT_STRINGVIEW_H
#define EXCELTABLEPROJECT_STRINGVIEW_H
#include "MyString.h"
class StringView
{
    const char* _begin;
    const char* _end; //1 element after the final char;

public:
    StringView(const char* begin, const char* end);
    StringView(const char* str); //terminatedString
    StringView(const MyString& string);

    size_t length() const;
    char operator[](size_t ind) const;

    StringView substr(size_t from, size_t length) const;
    friend std::ostream& operator<<(std::ostream&, const StringView& strView);

};

#endif //EXCELTABLEPROJECT_STRINGVIEW_H
