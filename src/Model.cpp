//
// Created by lucaberto on 14/12/24.
//

#include "Model.h"
#include "Function.h"

Model::Model(QObject *parent) : QStandardItemModel(10, 10, parent) {
    QStringList horizontalLabels;
    QStringList verticalLabels;
    for (int column = 0; column < QStandardItemModel::columnCount(); ++column)
        horizontalLabels.append(QChar('A' + column));
    for (int row = 0; row < QStandardItemModel::rowCount(); ++row)
        verticalLabels.append(QString::number(row + 1));
    setHorizontalHeaderLabels(horizontalLabels);
    setVerticalHeaderLabels(verticalLabels);
    connect(this, &QStandardItemModel::itemChanged, this, &Model::onItemChanged);
}

Model::~Model() {
    while (!observers.empty()) {
        Observer *observer = observers.front();
        delete observer;
    }
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

Observer *Model::getObserver(const QModelIndex &index) {
    for (auto observer : observers) {
        Function *function = dynamic_cast<Function *>(observer);
        if (function && function->thereIsFunction(index))
            return observer;
    }
    return nullptr;
}

void Model::onItemChanged(QStandardItem *item) {
    notify();
}
