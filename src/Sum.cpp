//
// Created by lucaberto on 30/11/24.
//

#include "Sum.h"

Sum::Sum(Model *model, const QModelIndex &index, const QModelIndexList &range, const std::string &formula) : Function(
    model, index, range, formula) {
}

void Sum::compute() {
    double sum = 0;
    for (const auto &index: range) {
        bool converted;
        double value = subject->itemFromIndex(index)->text().toDouble(&converted);
        if (converted)
            sum += value;
    }
    subject->itemFromIndex(index)->setText(QString::number(sum));
}