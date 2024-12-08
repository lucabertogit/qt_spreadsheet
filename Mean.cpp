//
// Created by lucaberto on 30/11/24.
//

#include "Mean.h"

Mean::Mean(Spreadsheet *s, const CellRange &r) : range(r), subject(s) {
    subject->addObserver(this);
}

Mean::~Mean() {
    subject->removeObserver(this);
}

void Mean::compute() {
}
