//
// Created by lucaberto on 30/11/24.
//

#ifndef MAX_H
#define MAX_H

#include "Function.h"
#include "Spreadsheet.h"

class Spreadsheet;

class Max : public Function {
public:
    Max(Spreadsheet *s, const CellRange &r);

    ~Max() override;

    void compute() override;

private:
    CellRange range;
    Spreadsheet *subject;
};

#endif //MAX_H