//
// Created by lucaberto on 30/11/24.
//

#include "Min.h"

Min::Min(Model *model, const QModelIndex &index, const QModelIndexList &range, const std::string &formula) : Function(
    model, index, range, formula) {
}

void Min::compute() {
    QModelIndex min = range[0];
    for (const auto &index : range) {
        if (subject->itemFromIndex(index)->text().toDouble() < subject->itemFromIndex(min)->text().toDouble())
            min = index;
    }
    subject->itemFromIndex(index)->setText(subject->itemFromIndex(min)->text());
}
