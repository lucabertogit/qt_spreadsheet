//
// Created by lucaberto on 30/11/24.
//

#ifndef SUM_H
#define SUM_H

#include "Function.h"
#include "Spreadsheet.h"

class Sum : public Function {
public:
    Sum(Spreadsheet *s, const std::string &range);

    ~Sum() override;

    void compute() override;

private:
    int firstColumn;
    int lastColumn;
    int firstRow;
    int lastRow;
    Spreadsheet *subject;
};

#endif //SUM_H
