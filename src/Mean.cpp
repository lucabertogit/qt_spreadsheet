//
// Created by lucaberto on 30/11/24.
//

#include "Mean.h"

Mean::Mean(Model *model, const QModelIndex &index, const QModelIndexList &range,
           const std::string &formula) : Function(
    model, index, range, formula) {
}

void Mean::compute() {
    double sum = 0;
    int countElement = 0;
    for (const auto &index: range) {
        countElement++;
        sum += subject->itemFromIndex(index)->text().toDouble();
    }
    double mean = sum / countElement;
    subject->itemFromIndex(index)->setText(QString::number(mean));
}
