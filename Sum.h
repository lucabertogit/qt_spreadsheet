//
// Created by lucaberto on 30/11/24.
//

#ifndef SUM_H
#define SUM_H

#include "Function.h"

class Sum : public Function {
public:
    Sum() = default;
    ~Sum() override = default;
    void compute() override;
};

#endif //SUM_H
