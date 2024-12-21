//
// Created by lucaberto on 14/12/24.
//

#include <regex>
#include <QLineEdit>
#include "Controller.h"
#include "FactoryFunction.h"

Controller::Controller(Model *m) : model(m) {
}

void Controller::execute(const QModelIndex &index, QWidget *editor) const {
    Function *function = dynamic_cast<Function *>(model->getObserver(index));
    QString oldItemText;
    if (function)
        oldItemText = QString::fromStdString(function->getExtendedFormula());
    else
        oldItemText = model->itemFromIndex(index)->text();
    QLineEdit *editorCell = qobject_cast<QLineEdit *>(editor);
    QString newItemText = editorCell->text();
    if (newItemText == oldItemText)
        return;
    
    if (oldItemText.length() > 0 && oldItemText[0] == '=')
        deleteFunction(index);
    
    try {
        if (newItemText.length() > 0 && newItemText[0] == '=')
            createFunction(index, newItemText);
    } catch (std::invalid_argument &e) {
        model->itemFromIndex(index)->setText("#NOME?");
    }
}

QModelIndexList Controller::setIndexes(char columnStart, char columnEnd, int rowStart, int rowEnd, const QModelIndex &index) const {
    QModelIndexList result;
    for (int row = rowStart; row <= rowEnd; ++row) {
        for (int col = columnToInt(columnStart); col <= columnToInt(columnEnd); ++col) {
            if (model->index(row, col) == index)
                // TODO: individuare eventuale errore piu' appropriato
                throw std::invalid_argument("Formula compresa nell'intervallo specificato");
            result.push_back(model->index(row, col));
        }
    }
    return result;
}

void Controller::createFunction(const QModelIndex &index, const QString &newItemText) const {
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

void Controller::deleteFunction(const QModelIndex &index) const {
    Observer *observer = model->getObserver(index);
    delete observer;
}

void Controller::deleteAllFunction() const {
    while (model->countObserver() > 0) {
        Observer *observer = model->getObserver();
        delete observer;;
    }
}

void Controller::printExtendedFormula(const QModelIndex &index, QWidget *editor) const {
    Function *function = dynamic_cast<Function *>(model->getObserver(index));
    if (function) {
        auto *editorCell = qobject_cast<QLineEdit *>(editor);
        editorCell->setText(QString::fromStdString(function->getExtendedFormula()));
    }
}
