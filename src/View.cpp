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
        // TODO: inserire formula estesa quando si entra in modifica
    }
    return result;
}

void View::commitData(QWidget *editor) {
    if (auto *lineEdit = qobject_cast<QLineEdit *>(editor)) {
        QModelIndex index = currentIndex();
        QString currentText = lineEdit->text();
        controller->execute(index, currentText);
    }
    QTableView::commitData(editor);
}
