//
// Created by lucaberto on 14/12/24.
//

#include "MainWindow.h"

MainWindow::MainWindow(View *v, QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags) {
    setCentralWidget(v);
    setWindowTitle("Spreadsheet");
}

MainWindow::~MainWindow() {
    takeCentralWidget();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    View *view = dynamic_cast<View *>(centralWidget());
    if (view)
        view->quit();
    QMainWindow::closeEvent(event);
}
