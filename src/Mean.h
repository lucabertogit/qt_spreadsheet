//
// Created by lucaberto on 30/11/24.
//

#ifndef MEAN_H
#define MEAN_H

#include "Function.h"

class Mean : public Function {
public:
    Mean(Model *model, const std::string &formula);

    ~Mean() override = default;

    void compute() override;
};

#endif //MEAN_H
