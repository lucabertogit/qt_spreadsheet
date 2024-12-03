//
// Created by lucaberto on 03/12/24.
//

#ifndef FACTORYFUNCTION_H
#define FACTORYFUNCTION_H

#include <string>

#include "Function.h"
#include "Spreadsheet.h"

class FactoryFunction {
public:
    Function *createFunction(Spreadsheet *s, const std::string &codeFunction, const std::string &range);
};

#endif //FACTORYFUNCTION_H
