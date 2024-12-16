//
// Created by lucaberto on 03/12/24.
//

#ifndef FACTORYFUNCTION_H
#define FACTORYFUNCTION_H

#include <string>

#include "Function.h"
#include "Model.h"

class FactoryFunction {
public:
    enum class CodeFunction { Sum, Max, Min, Mean };

    Function *createFunction(Model *model, CodeFunction code, const std::string &formula);

    CodeFunction codeToString(const std::string &code);
};

#endif //FACTORYFUNCTION_H
