//
// Created by lucaberto on 30/11/24.
//

#include "Min.h"

Min::Min(Spreadsheet *s, const CellRange &r) : range(r), subject(s) {
    subject->addObserver(this);
}

Min::~Min() {
    subject->removeObserver(this);
}

void Min::compute() {
}
