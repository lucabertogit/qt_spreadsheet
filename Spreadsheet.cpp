//
// Created by lucaberto on 29/11/24.
//

#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(QWidget *parent) : QMainWindow(parent),
                                            table(new QTableWidget(ROWS, COLS, this)) {
    table->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    for (int i = 0; i < COLS; i++) {
        QString character(QChar('A' + i));
        table->setHorizontalHeaderItem(i, new QTableWidgetItem(character));
    }
    table->setCurrentCell(0, 0);
    setCentralWidget(table);
    connect(table, &QTableWidget::itemChanged, this, &Spreadsheet::itemChanged);
    setWindowTitle("Spreadsheet");
}

Spreadsheet::~Spreadsheet() {
    delete table;
}

std::string Spreadsheet::getCodeFunction(const QTableWidgetItem *item) {
    std::size_t startRange = item->text().toStdString().find('(');
    if (startRange == std::string::npos) {
        throw std::invalid_argument("Codice funzione non valido");
    }
    std::string codeFunction = item->text().toStdString().substr(1, startRange - 1);
    std::cout << "Code Function: " << codeFunction << std::endl; // TODO: togliere utilizzato per prove
    return codeFunction;
}

CellRange Spreadsheet::getRange(const QTableWidgetItem *item) {
    std::size_t startRange = item->text().toStdString().find('(');
    std::size_t endRange = item->text().toStdString().find(')');
    if (startRange == std::string::npos || endRange == std::string::npos) {
        throw std::invalid_argument("Intervallo non valido");
    }
    std::string range = item->text().toStdString().substr(startRange + 1, endRange - startRange - 1);
    std::cout << "Range: " << range << std::endl; // TODO: togliere utilizzato per prove
    CellRange result;
    result.setRange(range);
    return result;
}

void Spreadsheet::addObserver(Observer *o) {
    observers.push_back(o);
}

void Spreadsheet::removeObserver(Observer *o) {
    observers.remove(o);
}

void Spreadsheet::notify() {
    for (auto observer : observers)
        observer->update();
}

void Spreadsheet::itemChanged(QTableWidgetItem *item) {
    std::string cell = item->text().toStdString();
    if (cell[0] == '=') {
        try {
            FactoryFunction factory;
            std::string codeFunction = getCodeFunction(item);
            CellRange cellRange = getRange(item);
            factory.createFunction(this, codeFunction, cellRange);
        } catch (std::invalid_argument &e) {
            item->setText("#NOME?");
        }
    }
    notify();
}