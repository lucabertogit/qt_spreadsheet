//
// Created by lucaberto on 29/11/24.
//

#include <iostream> // TODO: togliere utilizzato per prove
#include <string>

#include "Spreadsheet.h"
#include "FactoryFunction.h"

Spreadsheet::Spreadsheet(int rows, int cols, QWidget *parent) : QMainWindow(parent),
                                                                table(new QTableWidget(rows, cols, this)) {
    table->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    for (int i = 0; i < cols; i++) {
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
    std::string codeFunction;
    std::size_t startRange = item->text().toStdString().find("(");
    if (startRange != std::string::npos) {
        codeFunction = item->text().toStdString().substr(1, startRange - 1);
        std::cout << "Code Function: " << codeFunction << std::endl; // TODO: togliere utilizzato per prove
    }
    return codeFunction;
}

std::string Spreadsheet::getRange(const QTableWidgetItem *item) {
    std::string range;
    std::size_t startRange = item->text().toStdString().find("(");
    std::size_t endRange = item->text().toStdString().find(")");
    if (startRange != std::string::npos && endRange != std::string::npos) {
        range = item->text().toStdString().substr(startRange + 1, endRange - startRange - 1);
        std::cout << "Range: " << range << std::endl; // TODO: togliere utilizzato per prove
    }
    return range;
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
        FactoryFunction factory;
        std::string codeFunction = getCodeFunction(item);
        std::string range = getRange(item);
        Function *function = factory.createFunction(this, codeFunction, range);
        if (!function)
            item->setText("#NOME?");
    }
    notify();
}