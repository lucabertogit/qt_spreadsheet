//
// Created by lucaberto on 29/11/24.
//

#include <iostream>

#include "Spreadsheet.h"

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

Function * Spreadsheet::createFunction(QTableWidgetItem *item) {
    // TODO: implementare factory method
    std::size_t found = item->text().toStdString().find("(");
    if (found != std::string::npos) {
        std::string codeFunction = item->text().toStdString().substr(1, found - 1);
        if (codeFunction == "SUM") {
            std::cout << "SUM" << std::endl;
        } else if (codeFunction == "MAX") {
            std::cout << "MAX" << std::endl;
        } else if (codeFunction == "MIN") {
            std::cout << "MIN" << std::endl;
        } else if (codeFunction == "MEAN") {
            std::cout << "MEAN" << std::endl;
        }
    }
    return nullptr;
}

void Spreadsheet::itemChanged(QTableWidgetItem *item) {
    std::string cell = item->text().toStdString();
    if (cell[0] == '=') {
        observers.push_back(createFunction(item));
    }
}