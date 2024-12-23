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

    // TODO: potrebbe liberare la memoria allocati dagli observer il distruttore?
    ~Model() override = default;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

    int countObserver() const;

    Observer *getObserver();

    Observer *getObserver(const QModelIndex &index);


protected slots:
    void onItemChanged(QStandardItem *item);

private:
    std::list<Observer *> observers;
};

#endif //MODEL_H
