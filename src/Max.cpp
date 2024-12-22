//
// Created by lucaberto on 30/11/24.
//

#include "Max.h"

Max::Max(Model *model, const QModelIndex &index, const QModelIndexList &range, const std::string &formula) : Function(
    model, index, range, formula) {
}

void Max::compute() {
    QModelIndex max = range[0];
    for (const auto &index : range) {
        if (subject->itemFromIndex(index)->text().toDouble() > subject->itemFromIndex(max)->text().toDouble())
            max = index;
    }
    subject->itemFromIndex(index)->setText(subject->itemFromIndex(max)->text());
}
