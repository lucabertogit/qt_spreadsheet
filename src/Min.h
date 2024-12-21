//
// Created by lucaberto on 30/11/24.
//

#ifndef MIN_H
#define MIN_H

#include "Function.h"

class Min : public Function {
public:
    Min(Model *model, const QModelIndex &index, const QModelIndexList &indexes, const std::string &formula);

    ~Min() override = default;

    void compute() override;
};

#endif //MIN_H
