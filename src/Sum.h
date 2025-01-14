//
// Created by lucaberto on 30/11/24.
//

#ifndef SUM_H
#define SUM_H

#include "Function.h"

class Sum : public Function {
public:
    Sum(Model *model, const QModelIndex &index, const QModelIndexList &range, const std::string &formula);

    ~Sum() override = default;

    void compute() override;
};

#endif //SUM_H
