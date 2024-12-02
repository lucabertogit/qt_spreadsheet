//
// Created by lucaberto on 30/11/24.
//

#ifndef SUM_H
#define SUM_H

#include "Function.h"
#include "Spreadsheet.h"

class Sum : public Function {
public:
    Sum(Spreadsheet *s);

    ~Sum() override = default;

    void compute() override;

private:
    Spreadsheet *subject;
};

#endif //SUM_H
