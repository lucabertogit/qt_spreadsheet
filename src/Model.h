//
// Created by lucaberto on 14/12/24.
//

#ifndef MODEL_H
#define MODEL_H

#include <QStandardItemModel>

class Model : public QStandardItemModel {
public:
    Model(int rows, int columns, QObject *parent = nullptr);

    ~Model() override = default;

private:
};

#endif //MODEL_H
