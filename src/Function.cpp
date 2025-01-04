//
// Created by lucaberto on 02/12/24.
//

#include "Function.h"

Function::Function(Model *model, const QModelIndex &index, const QModelIndexList &range,
                   const std::string &formula) : index(index), range(range), extendedFormula(formula),
                                                 subject(model) {
    subject->addObserver(this);
}

Function::~Function() {
    subject->removeObserver(this);
}

const std::string &Function::getExtendedFormula() const {
    return extendedFormula;
}

const QModelIndex &Function::getIndex() const {
    return index;
}

bool Function::thereIsFunction(const QModelIndex &index) {
    if (this->index.row() == index.row() && this->index.column() == index.column())
        return true;
    return false;
}

void Function::update() {
    compute();
}
