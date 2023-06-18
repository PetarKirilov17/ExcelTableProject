#include <iostream>
#include "stringHelperFunctions.h"

#include "ExcelTable.h"

int main() {
    ExcelTable table;
    table.readTableFromFile("test.txt");
    table.printTable();
    return 0;
}