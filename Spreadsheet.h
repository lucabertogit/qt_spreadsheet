//
// Created by lucaberto on 29/11/24.
//

#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <list>
#include <string>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTableWidgetItem>

#include "Function.h"
#include "FactoryFunction.h"
#include "Subject.h"
#include "CellRange.h"


class Spreadsheet : public QMainWindow, public Subject {
    Q_OBJECT
public:
    explicit Spreadsheet(QWidget *parent = nullptr);

    ~Spreadsheet() override;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

public slots:
    void itemChanged(QTableWidgetItem *item);

private:
    // TODO: ricordarsi di liberare la memoria quando l'observer non serve più
    const int COLS{10};
    const int ROWS{10};
    QTableWidget *table;
    std::list<Observer*> observers;

    std::string getCodeFunction(const QTableWidgetItem *item);

    CellRange getRange(const QTableWidgetItem *item);
};

#endif //SPREADSHEET_H
