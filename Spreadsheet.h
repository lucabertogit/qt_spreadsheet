//
// Created by lucaberto on 29/11/24.
//

#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <list>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTableWidgetItem>

#include "Function.h"

class Spreadsheet : public QMainWindow {
    Q_OBJECT
public:
    explicit Spreadsheet(int rows = 10, int cols = 10, QWidget *parent = nullptr);

    ~Spreadsheet() override;

    Function *createFunction(QTableWidgetItem *item);

public slots:
    void itemChanged(QTableWidgetItem *item);

private:
    QTableWidget *table;
    std::list<Function*> observers;
};

#endif //SPREADSHEET_H
