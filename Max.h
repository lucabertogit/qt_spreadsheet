//
// Created by lucaberto on 30/11/24.
//

#ifndef MAX_H
#define MAX_H

#include "Function.h"
#include "Spreadsheet.h"

class Max : public Function {
public:
    Max(Spreadsheet *s);

    ~Max() override = default;

    void compute() override;

private:
    Spreadsheet *subject;
};

#endif //MAX_H
