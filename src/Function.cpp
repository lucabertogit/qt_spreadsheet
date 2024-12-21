//
// Created by lucaberto on 02/12/24.
//

#include <iostream>
#include "Function.h"

Function::Function(Model *model, const QModelIndex &index, const QModelIndexList &indexes,
                   const std::string &formula) : index(index), indexes(indexes), extendedFormula(formula),
                                                 subject(model) {
    std::cout << "Add Function -> " << this->extendedFormula << std::endl;
    subject->addObserver(this);
}

Function::~Function() {
    std::cout << "Remove Function -> " << this->extendedFormula << std::endl;
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
