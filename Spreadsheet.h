//
// Created by lucaberto on 29/11/24.
//

#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTableWidgetItem>

class Spreadsheet : public QMainWindow {
    Q_OBJECT
public:
    explicit Spreadsheet(int rows = 10, int cols = 10, QWidget *parent = nullptr);

    ~Spreadsheet() override;

public slots:
    void currentItemChanged(QTableWidgetItem *item);
    void itemChanged(QTableWidgetItem *item);
private:
    QTableWidget *table;
};

#endif //SPREADSHEET_H
