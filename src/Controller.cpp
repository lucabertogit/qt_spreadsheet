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
    if (newItemText == oldItemText)
        return;
    if (newItemText[0] == '=')
        // TODO: spostare su Model
        functions.push_back(createFunction(index, newItemText));
}

Function * Controller::createFunction(const QModelIndex &index, const QString &newItemText) {
    // TODO: implementare funzione
    FactoryFunction factory;
    std::string code;

    return factory.createFunction(model, factory.codeFromString(code), newItemText.toStdStr());
}
