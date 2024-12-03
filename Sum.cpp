//
// Created by lucaberto on 30/11/24.
//

#include "Sum.h"

Sum::Sum(Spreadsheet *s, const std::string &range) : subject(s) {
    subject->addObserver(this);
}

Sum::~Sum() {
    subject->removeObserver(this);
}

void Sum::compute() {
}
