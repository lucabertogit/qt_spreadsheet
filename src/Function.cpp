//
// Created by lucaberto on 02/12/24.
//

#include "Function.h"

Function::Function(Model *model, const QModelIndex &index, const std::string &formula) : extendedFormula(formula), index(index), subject(model) {
    subject->addObserver(this);
}

Function::~Function() {
    subject->removeObserver(this);
}

const std::string & Function::getExtendedFormula() const {
    return extendedFormula;
}

void Function::update() {
    compute();
}
