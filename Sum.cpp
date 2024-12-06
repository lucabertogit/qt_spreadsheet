//
// Created by lucaberto on 30/11/24.
//

#include "Sum.h"

Sum::Sum(Spreadsheet *s, const CellRange &r) : range(r), subject(s), item(s->getTable().currentItem()) {
    subject->addObserver(this);
}

Sum::~Sum() {
    subject->removeObserver(this);
}

void Sum::compute() {
    double sum = 0;
    for (int col = range.getStartColumn(); col <= range.getEndColumn(); col++) {
        for (int row = range.getStartRow(); row <= range.getEndRow(); row++) {
            sum += subject->getTable().item(row, col)->text().toDouble();
        }
    }
    item->setText(QString::number(sum));
}
