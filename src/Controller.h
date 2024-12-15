//
// Created by lucaberto on 14/12/24.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"

class Controller {
public:
    explicit Controller(Model *m);

    ~Controller();

    void setPrevContent(const QModelIndex &index);

private:
    Model *model;
    QStandardItem *prevItem;
};

#endif //CONTROLLER_H
