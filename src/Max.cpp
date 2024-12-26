//
// Created by lucaberto on 30/11/24.
//

#include "Max.h"

Max::Max(Model *model, const QModelIndex &index, const QModelIndexList &range, const std::string &formula) : Function(
    model, index, range, formula) {
}

void Max::compute() {
    QModelIndex max;
    for (auto index = range.begin(); !max.isValid() && index != range.end(); ++index) {
        bool converted;
        double value = subject->itemFromIndex(*index)->text().toDouble(&converted);
        if (converted)
            max = *index;
    }
    if (max.isValid()) {
        for (const auto &index : range) {
            bool converted;
            double value = subject->itemFromIndex(index)->text().toDouble(&converted);
            if (converted && value > subject->itemFromIndex(max)->text().toDouble())
                max = index;
        }
        subject->itemFromIndex(index)->setText(subject->itemFromIndex(max)->text());
    } else {
        subject->itemFromIndex(index)->setText(QString::number(0));
    }
}
