//
// Created by lucaberto on 14/12/24.
//

#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets/QTableView>
#include "Model.h"
#include "Controller.h"

class View : public QTableView {
public:
    explicit View(Model *m, Controller *c, QWidget *parent = nullptr);

    ~View() override = default;

protected:
    bool edit(const QModelIndex &index, QAbstractItemView::EditTrigger trigger, QEvent *event) override;

private:
    Model *model;
    Controller *controller;
};

#endif //VIEW_H
