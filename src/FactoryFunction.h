//
// Created by lucaberto on 03/12/24.
//

#ifndef FACTORYFUNCTION_H
#define FACTORYFUNCTION_H

#include <string>

#include "Function.h"
#include "Model.h"
#include "Sum.h"
#include "Max.h"
#include "Min.h"
#include "Mean.h"

class FactoryFunction {
public:
    enum class CodeFunction {
        Sum = "SUM",
        Max = "MAX",
        Min = "MIN",
        Mean = "MEAN"
    };

    Function *createFunction(Model *m, const CodeFunction code);

    CodeFunction getCode(const std::string &code);
};

#endif //FACTORYFUNCTION_H
