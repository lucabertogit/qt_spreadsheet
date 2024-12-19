//
// Created by lucaberto on 30/11/24.
//

#include "Min.h"

Min::Min(Model *model, const QModelIndex &index, const QModelIndexList &indexes, const std::string &formula) : Function(
    model, index, indexes, formula) {
}

void Min::compute() {
    QModelIndex min = indexes[0];
    for (const auto &index : indexes) {
        if (subject->itemFromIndex(index)->text().toDouble < subject->itemFromIndex(max)->text().toDouble)
            min = index;
    }
    subject->itemFromIndex(index)->setText(subject->itemFromIndex(min).text());
}
