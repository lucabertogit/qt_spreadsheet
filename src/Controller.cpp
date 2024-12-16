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
    std::vector<std::string> splitFormula;

    std::string formula = newItemText.toStdString();
    std::transform(formula.begin(), formula.end(), formula.begin(), ::toupper);
    std::smatch matches;
    std::regex pattern("^=(SUM|MAX|MIN|MEAN)\\(([A-Z])(\\d+):([A-Z])(\\d+)\\)$");
    while (std::regex_search(formula, matches, pattern)) {
        for (auto match : matches) {
            splitFormula.push_back(match);
        }
        formula = matches.suffix().str();
    }

    // TODO: creare QModelIndexList che dovrà essere passato come parametro

    factory.createFunction(model, factory.codeFromString(splitFormula[1]), index, splitFormula[0]);
}
