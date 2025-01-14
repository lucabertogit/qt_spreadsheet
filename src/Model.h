//
// Created by lucaberto on 14/12/24.
//

#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <QStandardItemModel>
#include "Subject.h"

class Model : public QStandardItemModel, public Subject {
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

    ~Model() override;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

    Observer *getObserver(const QModelIndex &index);


protected slots:
    void onItemChanged(QStandardItem *item);

private:
    std::list<Observer *> observers;
};

#endif //MODEL_H
