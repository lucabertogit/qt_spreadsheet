//
// Created by lucaberto on 03/12/24.
//

#include "FactoryFunction.h"
#include "Sum.h"
#include "Max.h"
#include "Min.h"
#include "Mean.h"

Function *FactoryFunction::createFunction(Spreadsheet *s, const std::string &codeFunction, const std::string &range) {
    // TODO: scomporre range in valori interi
    int firstColumn;
    int lastColumn;
    int firstRow;
    int lastRow;

    if (codeFunction == "SUM") {
        return new Sum(s, range);
    } else if (codeFunction == "MAX") {
        return new Max(s, range);
    } else if (codeFunction == "MIN") {
        return new Min(s, range);
    } else if (codeFunction == "MEAN") {
        return new Mean(s, range);
    }
    return nullptr;
}
