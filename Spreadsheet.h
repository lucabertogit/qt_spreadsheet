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
#include "Subject.h"

class Spreadsheet : public QMainWindow, public Subject {
    Q_OBJECT
public:
    explicit Spreadsheet(int rows = 10, int cols = 10, QWidget *parent = nullptr);

    ~Spreadsheet() override;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

public slots:
    void itemChanged(QTableWidgetItem *item);

private:
    // TODO: ricordarsi di liberare la memoria quando l'observer non serve più
    QTableWidget *table;
    std::list<Observer*> observers;

    std::string getCodeFunction(const QTableWidgetItem *item);

    std::string getRange(const QTableWidgetItem *item);
};

#endif //SPREADSHEET_H
