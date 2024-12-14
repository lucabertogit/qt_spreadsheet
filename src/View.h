//
// Created by lucaberto on 14/12/24.
//

#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets/QTableView>
#include "Model.h"

class View : public QTableView {
public:
    explicit View(Model *m, QWidget *parent = nullptr);

    ~View() override = default;

private:
    Model *model;
};

#endif //VIEW_H
