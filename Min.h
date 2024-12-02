//
// Created by lucaberto on 30/11/24.
//

#ifndef MIN_H
#define MIN_H

#include "Function.h"
#include "Spreadsheet.h"

class Min : public Function {
public:
    Min(Spreadsheet *s);

    ~Min() override = default;

    void compute() override;

private:
    Spreadsheet *subject;
};

#endif //MIN_H
