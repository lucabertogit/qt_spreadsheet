//
// Created by lucaberto on 30/11/24.
//

#include "Sum.h"

Sum::Sum(Model *model, const QModelIndex &index, const QModelIndexList &indexes, const std::string &formula) : Function(
    model, index, indexes, formula) {
}

void Sum::compute() {
    double sum = 0;
    for (const auto& index : indexes) {
        sum += subject->itemFromIndex(index)->text().toDouble();
    }
    subject->itemFromIndex(index)->setText(QString::number(sum));
}