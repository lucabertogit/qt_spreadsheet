//
// Created by lucaberto on 09/12/24.
//

#include "gtest/gtest.h"
#include "../src/Spreadsheet.h"

TEST(Spreadsheet, TestCostructor) {
    Spreadsheet sheet;
    QTableWidgetItem *itemHeader;

    ASSERT_EQ(sheet.getTable().columnCount(), 10);
    ASSERT_EQ(sheet.getTable().rowCount(), 10);

    ASSERT_EQ(sheet.getTable().sizeAdjustPolicy(), QTableWidget::AdjustToContents);

    itemHeader = sheet.getTable().horizontalHeaderItem(0);
    ASSERT_EQ(itemHeader->text(), 'A');
    itemHeader = sheet.getTable().horizontalHeaderItem(1);
    ASSERT_EQ(itemHeader->text(), 'B');
    itemHeader = sheet.getTable().horizontalHeaderItem(2);
    ASSERT_EQ(itemHeader->text(), 'C');
    itemHeader = sheet.getTable().horizontalHeaderItem(3);
    ASSERT_EQ(itemHeader->text(), 'D');
    itemHeader = sheet.getTable().horizontalHeaderItem(4);
    ASSERT_EQ(itemHeader->text(), 'E');
    itemHeader = sheet.getTable().horizontalHeaderItem(5);
    ASSERT_EQ(itemHeader->text(), 'F');
    itemHeader = sheet.getTable().horizontalHeaderItem(6);
    ASSERT_EQ(itemHeader->text(), 'G');
    itemHeader = sheet.getTable().horizontalHeaderItem(7);
    ASSERT_EQ(itemHeader->text(), 'H');
    itemHeader = sheet.getTable().horizontalHeaderItem(8);
    ASSERT_EQ(itemHeader->text(), 'I');
    itemHeader = sheet.getTable().horizontalHeaderItem(9);
    ASSERT_EQ(itemHeader->text(), 'J');

    ASSERT_EQ(sheet.getTable().currentRow(), 0);
    ASSERT_EQ(sheet.getTable().currentColumn(), 0);

    ASSERT_EQ(sheet.centralWidget(), &(sheet.getTable()));

    ASSERT_EQ(sheet.windowTitle(), QString("Spreadsheet"));
}

TEST(Spreadsheet, TestGetRange) {
    Spreadsheet sheet;
    CellRange range;
    QTableWidgetItem item;

    try {
        item.setText("=15");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=(15");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=15)");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=(15)");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM15");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM(15");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM15)");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM(15)");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=A1:C10");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=(A1:C10");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=A1:C10)");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    item.setText("=(A1:C10)");
    range = sheet.getRange(&item);
    ASSERT_EQ(range.getStartColumn(), 0);
    ASSERT_EQ(range.getStartRow(), 0);
    ASSERT_EQ(range.getEndColumn(), 2);
    ASSERT_EQ(range.getEndRow(), 9);

    try {
        item.setText("=SUMA1:C10");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM(A1:C10");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUMA1:C10)");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    item.setText("=SUM(A1:C10)");
    range = sheet.getRange(&item);
    ASSERT_EQ(range.getStartColumn(), 0);
    ASSERT_EQ(range.getStartRow(), 0);
    ASSERT_EQ(range.getEndColumn(), 2);
    ASSERT_EQ(range.getEndRow(), 9);

    try {
        item.setText("=[15");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=15]");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=[15]");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM15");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM[15");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM15]");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM[15]");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=[A1:C10");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=A1:C10]");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=[A1:C10]");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUMA1:C10");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM[A1:C10");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUMA1:C10]");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM[A1:C10]");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUM((A1:C10");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        item.setText("=SUMA1:C10))");
        range = sheet.getRange(&item);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    item.setText("=SUM((A1:C10))");
    range = sheet.getRange(&item);
    ASSERT_EQ(range.getStartColumn(), 0);
    ASSERT_EQ(range.getStartRow(), 0);
    ASSERT_EQ(range.getEndColumn(), 2);
    ASSERT_EQ(range.getEndRow(), 9);

    item.setText("=SUM((A1:C10)");
    range = sheet.getRange(&item);
    ASSERT_EQ(range.getStartColumn(), 0);
    ASSERT_EQ(range.getStartRow(), 0);
    ASSERT_EQ(range.getEndColumn(), 2);
    ASSERT_EQ(range.getEndRow(), 9);

    item.setText("=SUM(A1:C10))");
    range = sheet.getRange(&item);
    ASSERT_EQ(range.getStartColumn(), 0);
    ASSERT_EQ(range.getStartRow(), 0);
    ASSERT_EQ(range.getEndColumn(), 2);
    ASSERT_EQ(range.getEndRow(), 9);
}
