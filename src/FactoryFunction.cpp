//
// Created by lucaberto on 03/12/24.
//

#include <algorithm>
#include "FactoryFunction.h"
#include "Sum.h"
#include "Max.h"
#include "Min.h"
#include "Mean.h"

Function * FactoryFunction::createFunction(Model *model, const CodeFunction code, const std::string &formula) {
    switch (code) {
        case CodeFunction::Sum:
            return new Sum(model, formula);
        case CodeFunction::Max:
            return new Max(model, formula);
        case CodeFunction::Min:
            return new Min(model, formula);
        case CodeFunction::Mean:
            return new Mean(model, formula);
        default:
            throw std::invalid_argument("Funzione non disponibile");
    }
}

FactoryFunction::CodeFunction FactoryFunction::codeFromString(const std::string &code) {
    std::string codeFunction = code;
    std::transform(codeFunction.begin(), codeFunction.end(), codeFunction.begin(), ::toupper);
    if (codeFunction == "SUM")
        return CodeFunction::Sum;
    else if (codeFunction == "MAX")
        return CodeFunction::Max;
    else if (codeFunction == "MIN")
        return CodeFunction::Min;
    else if (codeFunction == "MEAN")
        return CodeFunction::Mean;
    else
        throw std::invalid_argument("Codice funzione non disponibile");
}
