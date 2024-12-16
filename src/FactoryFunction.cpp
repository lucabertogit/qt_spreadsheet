//
// Created by lucaberto on 03/12/24.
//

#include "FactoryFunction.h"

// TODO: rimuovere
/*
Function *FactoryFunction::createFunction(Spreadsheet *s, const std::string &codeFunction, const CellRange &range) {
    std::string code = codeFunction;
    toUpper(code);
    if (code == "SUM") {
        return new Sum(s, range);
    } else if (code == "MAX") {
        return new Max(s, range);
    } else if (code == "MIN") {
        return new Min(s, range);
    } else if (code == "MEAN") {
        return new Mean(s, range);
    } else {
        throw std::invalid_argument("Funzione non valida");
    }
}
*/

Function * FactoryFunction::createFunction(Model *m, const CodeFunction code) {
    switch (code) {
        case CodeFunction::Sum:
            return new Sum();
        case CodeFunction::Max:
            return new Max();
        case CodeFunction::Min:
            return new Min();
        case CodeFunction::Mean:
            return new Mean();
        default:
            throw std::invalid_argument("Funzione non disponibile");
    }
}

FactoryFunction::CodeFunction FactoryFunction::getCode(const std::string &code) {
    // TODO: implementare funzione
}
