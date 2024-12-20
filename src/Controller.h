//
// Created by lucaberto on 14/12/24.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"

class Controller {
public:
    explicit Controller(Model *m);

    ~Controller() = default;

    void execute(const QModelIndex &index, const QString &newItemText);

    QModelIndexList setIndexes(char columnStart, char columnEnd, int rowStart, int rowEnd, const QModelIndex &index);

    void createFunction(const QModelIndex &index, const QString &newItemText);

    int columnToInt(char column) const;

    template <typename T>
    void sortAndSwap(T start, T end) const;

    void deleteFunction(const QModelIndex &index);

    void deleteAllFunction();

    void writeExtendedFormula(const QModelIndex &index);

private:
    Model *model;
};

#endif //CONTROLLER_H
