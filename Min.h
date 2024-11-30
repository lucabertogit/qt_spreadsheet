//
// Created by lucaberto on 30/11/24.
//

#ifndef MIN_H
#define MIN_H

#include "Function.h"

class Min : public Function {
public:
    Min() = default;
    ~Min() override = default;
    void compute() override;
};

#endif //MIN_H
