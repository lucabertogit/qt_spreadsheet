//
// Created by lucaberto on 14/12/24.
//

#include "Model.h"

Model::Model(int rows, int columns, QObject *parent) : QStandardItemModel(rows, columns, parent) {
    QStringList horizontalLabels;
    QStringList verticalLabels;
    for (int column = 0; column < QStandardItemModel::columnCount(); ++column)
        horizontalLabels.append(QChar('A' + column));
    for (int row = 0; row < QStandardItemModel::rowCount(); ++row)
        verticalLabels.append(QString::number(row + 1));
    setHorizontalHeaderLabels(horizontalLabels);
    setVerticalHeaderLabels(verticalLabels);
}

void Model::addObserver(Observer *o) {
    observers.push_back(o);
}

void Model::removeObserver(Observer *o) {
    observers.remove(o);
}

void Model::notify() {
    for (const auto observer: observers)
        observer->update();
}
