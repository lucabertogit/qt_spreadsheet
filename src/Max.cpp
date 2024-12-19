//
// Created by lucaberto on 30/11/24.
//

#include "Max.h"

Max::Max(Model *model, const QModelIndex &index, const QModelIndexList &indexes, const std::string &formula) : Function(
    model, index, indexes, formula) {
}

void Max::compute() {
    QModelIndex max = indexes[0];
    for (const auto &index : indexes) {
        if (subject->itemFromIndex(index)->text().toDouble() > subject->itemFromIndex(max)->text().toDouble())
            max = index;
    }
    subject->itemFromIndex(index)->setText(subject->itemFromIndex(max)->text());
}
