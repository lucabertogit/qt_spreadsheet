//
// Created by lucaberto on 30/11/24.
//

#include "Max.h"

Max::Max(Spreadsheet *s, const CellRange &r) : range(r), subject(s) {
    subject->addObserver(this);
}

Max::~Max() {
    subject->removeObserver(this);
}

void Max::compute() {
}
