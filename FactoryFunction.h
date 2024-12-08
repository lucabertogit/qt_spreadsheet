//
// Created by lucaberto on 03/12/24.
//

#ifndef FACTORYFUNCTION_H
#define FACTORYFUNCTION_H

#include <string>

#include "Function.h"
#include "Spreadsheet.h"
#include "CellRange.h"
#include "Sum.h"
#include "Max.h"
#include "Min.h"
#include "Mean.h"

class FactoryFunction {
public:
    Function *createFunction(Spreadsheet *s, const std::string &codeFunction, const CellRange &range);
};

#endif //FACTORYFUNCTION_H
