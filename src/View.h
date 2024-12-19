//
// Created by lucaberto on 14/12/24.
//

#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets/QTableView>
#include "Model.h"
#include "Controller.h"

// TODO: valutare di utilizzare QTableWidget
class View : public QTableView {
    Q_OBJECT
public:
    explicit View(Model *m, Controller *c, QWidget *parent = nullptr);

    ~View() override = default;

    void quit();

protected:
    bool edit(const QModelIndex &index, QAbstractItemView::EditTrigger trigger, QEvent *event) override;

protected slots:
    void commitData(QWidget *editor) override;

private:
    Model *model;
    Controller *controller;
};

#endif //VIEW_H
