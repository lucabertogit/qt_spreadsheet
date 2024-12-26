//
// Created by lucaberto on 30/11/24.
//

#include "Min.h"

Min::Min(Model *model, const QModelIndex &index, const QModelIndexList &range, const std::string &formula) : Function(
    model, index, range, formula) {
}

void Min::compute() {
    QModelIndex min;
    for (auto index = range.begin(); !min.isValid() && index != range.end(); ++index) {
        bool converted;
        double value = subject->itemFromIndex(*index)->text().toDouble(&converted);
        if (converted)
            min = *index;
    }
    if (min.isValid()) {
        for (const auto &index : range) {
            bool converted;
            double value = subject->itemFromIndex(index)->text().toDouble(&converted);
            if (converted && value < subject->itemFromIndex(min)->text().toDouble())
                min = index;
        }
        subject->itemFromIndex(index)->setText(subject->itemFromIndex(min)->text());
    } else {
        subject->itemFromIndex(index)->setText(QString::number(0));
    }
}
