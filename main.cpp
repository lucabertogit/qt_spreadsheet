#include <QtWidgets/QApplication>

#include "Spreadsheet.h"

int main(int argc, char **argv) {
    QApplication a(argc, argv);

    Spreadsheet sheet;
    sheet.show();

    return a.exec();
}