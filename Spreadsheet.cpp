//
// Created by lucaberto on 29/11/24.
//

#include <string>

#include "Spreadsheet.h"
#include "Sum.h"
#include "Max.h"
#include "Min.h"
#include "Mean.h"

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

void Spreadsheet::createFunction(QTableWidgetItem *item) {
    Function *function = nullptr;
    std::size_t found = item->text().toStdString().find("(");
    if (found != std::string::npos) {
        std::string codeFunction = item->text().toStdString().substr(1, found - 1);
        if (codeFunction == "SUM") {
            function = new Sum(this);
        } else if (codeFunction == "MAX") {
            function = new Max(this);
        } else if (codeFunction == "MIN") {
            function = new Min(this);
        } else if (codeFunction == "MEAN") {
            function = new Mean(this);
        }
    }
    if (!function)
        item->setText("#NOME?");
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
        createFunction(item);
    }
    notify();
}
