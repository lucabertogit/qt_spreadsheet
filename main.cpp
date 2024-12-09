#include <QtWidgets/QApplication>

#include "src/Spreadsheet.h"

int main(int argc, char **argv) {
    QApplication a(argc, argv);

    Spreadsheet sheet;
    sheet.show();

    return a.exec();
}