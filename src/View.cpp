//
// Created by lucaberto on 14/12/24.
//

#include <QtWidgets/QTableWidget>
#include <QtWidgets/QLineEdit>
#include "View.h"

View::View(Model *m, Controller *c, QWidget *parent) : QTableView(parent), model(m), controller(c) {
    QTableView::setModel(model);
    setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    setCurrentIndex(model->indexFromItem(model->item(0, 0)));
}

bool View::edit(const QModelIndex &index, QAbstractItemView::EditTrigger trigger, QEvent *event) {
    bool result = QTableView::edit(index, trigger, event);
    if (result) {
        QLineEdit *editor = qobject_cast<QLineEdit *>(indexWidget(index));
        QString formula = controller->printExtendedFormula(index);
        if (!formula.isEmpty() && editor) {
            editor->setText(formula);
            editor->selectAll();
        }
    }
    return result;
}

void View::commitData(QWidget *editor) {
    QModelIndex index = currentIndex();
    controller->execute(index, editor);
    QTableView::commitData(editor);
}
