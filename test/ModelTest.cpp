//
// Created by lucaberto on 21/12/24.
//

#include "gtest/gtest.h"
#include "../src/Model.h"

TEST(Model, TestCostructor) {
    Model model;
    ASSERT_EQ(model.rowCount(), 10);
    ASSERT_EQ(model.columnCount(), 10);

    QStandardItem *header = model.horizontalHeaderItem(0);
    ASSERT_EQ(header->text().toStdString(), "A");

    header = model.horizontalHeaderItem(1);
    ASSERT_EQ(header->text().toStdString(), "B");

    header = model.horizontalHeaderItem(2);
    ASSERT_EQ(header->text().toStdString(), "C");

    header = model.horizontalHeaderItem(3);
    ASSERT_EQ(header->text().toStdString(), "D");

    header = model.horizontalHeaderItem(4);
    ASSERT_EQ(header->text().toStdString(), "E");

    header = model.horizontalHeaderItem(5);
    ASSERT_EQ(header->text().toStdString(), "F");

    header = model.horizontalHeaderItem(6);
    ASSERT_EQ(header->text().toStdString(), "G");

    header = model.horizontalHeaderItem(7);
    ASSERT_EQ(header->text().toStdString(), "H");

    header = model.horizontalHeaderItem(8);
    ASSERT_EQ(header->text().toStdString(), "I");

    header = model.horizontalHeaderItem(9);
    ASSERT_EQ(header->text().toStdString(), "J");

    header = model.verticalHeaderItem(0);
    ASSERT_EQ(header->text().toInt(), 1);

    header = model.verticalHeaderItem(1);
    ASSERT_EQ(header->text().toInt(), 2);

    header = model.verticalHeaderItem(2);
    ASSERT_EQ(header->text().toInt(), 3);

    header = model.verticalHeaderItem(3);
    ASSERT_EQ(header->text().toInt(), 4);

    header = model.verticalHeaderItem(4);
    ASSERT_EQ(header->text().toInt(), 5);

    header = model.verticalHeaderItem(5);
    ASSERT_EQ(header->text().toInt(), 6);

    header = model.verticalHeaderItem(6);
    ASSERT_EQ(header->text().toInt(), 7);

    header = model.verticalHeaderItem(7);
    ASSERT_EQ(header->text().toInt(), 8);

    header = model.verticalHeaderItem(8);
    ASSERT_EQ(header->text().toInt(), 9);

    header = model.verticalHeaderItem(9);
    ASSERT_EQ(header->text().toInt(), 10);
}