//
// Created by lucaberto on 14/12/24.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <list>
#include "Model.h"
#include "Function.h"

class Controller {
public:
    explicit Controller(Model *m);

    ~Controller() = default;

    void execute(const QModelIndex &index, const QString &newItemText);

    void createFunction(const QModelIndex &index, const QString &newItemText);

private:
    Model *model;
    std::list<Function*> functions;
};

#endif //CONTROLLER_H
