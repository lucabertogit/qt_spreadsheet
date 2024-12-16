//
// Created by lucaberto on 14/12/24.
//

#include "Controller.h"
#include "FactoryFunction.h"

Controller::Controller(Model *m) : model(m) {
}

void Controller::setPrevContent(const QModelIndex &index) {
    prevItemText = model->itemFromIndex(index)->text();
}

void Controller::execute(const QString &currentItemText) {
    // TODO: esaminare tutte le varie casistiche
    if (currentItemText != prevItemText)
        if (currentItemText[0] == '=')
            createFunction();
    prevItemText.clear();
}

void Controller::createFunction(const QString &currentItemText) {
    FactoryFunction factory;
    // TODO: implementare funzione
}
