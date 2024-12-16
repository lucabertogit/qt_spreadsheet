//
// Created by lucaberto on 14/12/24.
//

#include "Controller.h"
#include "FactoryFunction.h"

Controller::Controller(Model *m) : model(m) {
}

void Controller::execute(const QModelIndex &index, const QString &newItemText) {
    // TODO: esaminare tutte le varie casistiche
    QString oldItemText = model->itemFromIndex(index)->text();
    if (newItemText == oldItemText)
        return;
    if (newItemText[0] == '=')
        createFunction(index, newItemText);
}

void Controller::createFunction(const QModelIndex &index, const QString &newItemText) {
    // TODO: implementare funzione
    FactoryFunction factory;
    std::string code;

    factory.createFunction(model, factory.codeFromString(code), index, newItemText.toStdString());
}
