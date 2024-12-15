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
    Function *createFunction(Model *m, const std::string &formula);
};

#endif //FACTORYFUNCTION_H
