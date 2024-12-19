//
// Created by lucaberto on 30/11/24.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "Observer.h"
#include "Model.h"

class Function : public Observer {
public:
    Function(Model *model, const QModelIndex &index, const QModelIndexList &indexes, const std::string &formula);

    ~Function() override;

    void update() override;

    virtual void compute() = 0;

    const std::string &getExtendedFormula() const;

    const QModelIndex &getIndex() const;

    bool isFunction(const QModelIndex &index);

protected:
    QModelIndex index;
    QModelIndexList indexes;
    std::string extendedFormula;
    Model *subject;
};

#endif //FUNCTION_H
