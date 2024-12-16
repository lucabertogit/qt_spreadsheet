//
// Created by lucaberto on 14/12/24.
//

#include "Controller.h"
#include "FactoryFunction.h"

Controller::Controller(Model *m) : model(m) {
}

void Controller::execute(const QModelIndex &index, const QString &newItemText) {
    // TODO: esaminare tutte le varie casistiche
    QString oldItemText = model->itemFromIndex(index)->txt();
    if (newItemText != oldItemText)
        if (newItemText[0] == '=')
            createFunction(index, newItemText);
    prevItemText.clear();
}

void Controller::createFunction(const QModelIndex &index, const QString &newItemText) {
    FactoryFunction factory;
    std::string codeFunction;
    // TODO: implementare funzione
}
