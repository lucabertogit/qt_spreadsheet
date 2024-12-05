//
// Created by lucaberto on 03/12/24.
//

#include "FactoryFunction.h"

Function *FactoryFunction::createFunction(Spreadsheet *s, const std::string &codeFunction, const CellRange &range) {
    if (codeFunction == "SUM") {
        return new Sum(s, range);
    } else if (codeFunction == "MAX") {
        return new Max(s, range);
    } else if (codeFunction == "MIN") {
        return new Min(s, range);
    } else if (codeFunction == "MEAN") {
        return new Mean(s, range);
    }
    // TODO: anziche' passare nullptr lanciare un eccezione
    return nullptr;
}
