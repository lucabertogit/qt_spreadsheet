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

Function * FactoryFunction::createFunction(Model *m, const std::string &formula) {
    // TODO: implementare funzione
}