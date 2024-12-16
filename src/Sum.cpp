//
// Created by lucaberto on 30/11/24.
//

#include "Sum.h"

Sum::Sum(Model *model, const std::string &formula) : Function(model, formula) {
}

void Sum::compute() {
    // TODO: modificare a seguito delle variazioni effettuate
}

/*
void Sum::compute() {
    double sum = 0;
    for (int col = range.getStartColumn(); col <= range.getEndColumn(); col++) {
        for (int row = range.getStartRow(); row <= range.getEndRow(); row++) {
            sum += subject->getTable().item(row, col)->text().toDouble();
        }
    }
    item->setText(QString::number(sum));
}
*/