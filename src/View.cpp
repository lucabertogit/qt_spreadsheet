//
// Created by lucaberto on 14/12/24.
//

#include <QtWidgets/QTableWidget>
#include "View.h"

View::View(Model *m, QWidget *parent) : QTableView(parent), model(m) {
    QTableView::setModel(model);
    setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    setCurrentIndex(model->indexFromItem(model->item(0, 0)));
}
