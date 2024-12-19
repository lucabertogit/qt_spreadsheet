//
// Created by lucaberto on 14/12/24.
//

#include <regex>
#include "Controller.h"
#include "FactoryFunction.h"

Controller::Controller(Model *m) : model(m) {
}

void Controller::execute(const QModelIndex &index, const QString &newItemText) {
    QString oldItemText = model->itemFromIndex(index)->text();
    if (newItemText == oldItemText)
        return;
    
    if (oldItemText[0] == '=')
        deleteFunction(index);
    
    if (newItemText[0] == '=')
        createFunction(index, newItemText);
}

QModelIndexList Controller::setIndexes(char columnStart, char columnEnd, int rowStart, int rowEnd, const QModelIndex &index) {
    QModelIndexList result;
    for (int row = rowStart; rowStart <= rowEnd; ++rowStart) {
        for (int col = columnToInt(columnStart); col <= columnToInt(columnEnd); ++col) {
            if (model->index(row, col) == index)
                // TODO: individuare eventuale errore piu' appropriato
                throw std::invalid_argument("Formula compresa nell'intervallo specificato");
            result.push_back(model->index(row, col));
        }
    }
    return result;
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
        rowStart = std::stoi(matches[3].str()) - 1;
        columnEnd = matches[4].str()[0];
        rowEnd = std::stoi(matches[5].str()) - 1;
    } else {
        // TODO: individuare eventuale errore piu' appropriato
        throw std::invalid_argument("La stringa non corrisponde al formato atteso");
    }
    
    if (rowStart >= model->rowCount() || rowEnd >= model->rowCount())
        // TODO: individuare eventuale errore piu' appropriato
        throw std::invalid_argument("La stringa non corrisponde al formato atteso");
    
    QModelIndexList indexes = setIndexes(columnStart, columnEnd, rowStart, rowEnd, index);

    FactoryFunction::CodeFunction code = factory.codeFromString(function);

    sortAndSwap<char>(columnStart, columnEnd);
    sortAndSwap<int>(rowStart, rowEnd);

    factory.createFunction(model, code, index, indexes, formula);
}

int Controller::columnToInt(char column) const {
    return column - 'A';
}

template<typename T>
void Controller::sortAndSwap(T start, T end) const {
    if (start > end) {
        T tmp = start;
        start = end;
        end = tmp;
    }
}

void Controller::deleteFunction(const QModelIndex &index) {
    if (Observer *observer = model->getObserver(index)) {
        if (Function *function = dynamic_cast<Function *>(observer))
            delete function;
    }
}
