//
// Created by lucaberto on 14/12/24.
//

#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <QStandardItemModel>
#include "Subject.h"

class Model : public QStandardItemModel, public Subject {
public:
    Model(int rows, int columns, QObject *parent = nullptr);

    ~Model() override = default;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

protected slots:
    void onItemChanged(QStandardItem *item);

private:
    std::list<Observer *> observers;
};

#endif //MODEL_H
