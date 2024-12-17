//
// Created by lucaberto on 14/12/24.
//

#include <regex>
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
    FactoryFunction factory;
    std::string formula = newItemText.toStdString();
    std::transform(formula.begin(), formula.end(), formula.begin(), ::toupper);
    std::string function;
    char columnStart;
    char columnEnd;
    int rowStart;
    int rowEnd;


    std::regex pattern(R"(^=(SUM|MAX|MIN|MEAN)\(([A-J])(\d+):([A-J])(\d+)\)$)");
    std::smatch matches;
    if (std::regex_match(formula, matches, pattern)) {
        function = matches[1];
        columnStart = matches[2].str()[0];
        rowStart = std::stoi(matches[3].str());
        columnEnd = matches[4].str()[0];
        rowEnd = std::stoi(matches[5].str());
    } else {
        // TODO: individuare errore piu' appropriato
        throw std::invalid_argument("La stringa non corrisponde al formato atteso");
    }

    // TODO: creare QModelIndexList che dovrà essere passato come parametro

    factory.createFunction(model, factory.codeFromString(splitFormula[1]), index, splitFormula[0]);
}
