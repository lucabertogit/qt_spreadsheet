//
// Created by lucaberto on 14/12/24.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "View.h"

class MainWindow : public QMainWindow {
public:
    explicit MainWindow(View *v, QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    ~MainWindow() override;
};

#endif //MAINWINDOW_H
