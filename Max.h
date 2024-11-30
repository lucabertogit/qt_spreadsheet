//
// Created by lucaberto on 30/11/24.
//

#ifndef MAX_H
#define MAX_H

#include "Function.h"

class Max : public Function {
public:
    Max() = default;
    ~Max() override = default;
    void compute() override;
};

#endif //MAX_H
