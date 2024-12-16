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

    void setPrevContent(const QModelIndex &index);

    void execute(const QString &currentItemText);

    void createFunction(const QString &currentItemText);

private:
    Model *model;
    QString prevItemText;
    std::list<Function*> functions;
};

#endif //CONTROLLER_H
