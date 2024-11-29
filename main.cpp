#include <iostream>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char **argv) {
    QApplication a(argc, argv);

    QMainWindow window;
    window.show();

    return a.exec();
}