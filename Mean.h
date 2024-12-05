//
// Created by lucaberto on 30/11/24.
//

#ifndef MEAN_H
#define MEAN_H

#include "Function.h"
#include "Spreadsheet.h"

class Mean : public Function {
public:
    Mean(Spreadsheet *s, const CellRange &r);

    ~Mean() override;

    void compute() override;

private:
    CellRange range;
    Spreadsheet *subject;
};

#endif //MEAN_H
