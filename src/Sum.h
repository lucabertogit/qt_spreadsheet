//
// Created by lucaberto on 30/11/24.
//

#ifndef SUM_H
#define SUM_H

#include "Function.h"
#include "Spreadsheet.h"

class Spreadsheet;

class Sum : public Function {
public:
    Sum(Spreadsheet *s, const CellRange &r);

    ~Sum() override;

    void compute() override;

private:
    CellRange range;
    Spreadsheet *subject;
    QTableWidgetItem *item;
};

#endif //SUM_H
