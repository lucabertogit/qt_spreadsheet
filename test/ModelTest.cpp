//
// Created by lucaberto on 21/12/24.
//

#include "gtest/gtest.h"
#include "../src/Model.h"
#include "../src/Controller.h"
#include "../src/View.h"
#include "../src/Sum.h"
#include "../src/Max.h"

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

TEST(Model, TestAddObserver) {
    Model model;
    Controller controller(&model);
    View view(&model, &controller);

    QModelIndex index1 = model.index(3, 0);
    QModelIndexList range1;
    range1.push_back(model.index(0, 0));
    range1.push_back(model.index(1, 0));
    range1.push_back(model.index(2, 0));
    Sum sumFormula(&model, index1, range1, "=SUM(A1:A3)");
    ASSERT_EQ(model.countObserver(), 1);

    QModelIndex index2 = model.index(3, 1);
    QModelIndexList range2;
    range1.push_back(model.index(0, 1));
    range1.push_back(model.index(1, 1));
    range1.push_back(model.index(2, 1));
    Max maxFormula(&model, index2, range2, "=MAX(B1:B3)");
    ASSERT_EQ(model.countObserver(), 2);
}

TEST(Model, TestRemoveObserver) {
    Model model;
    Controller controller(&model);
    View view(&model, &controller);

    QModelIndex index1 = model.index(3, 0);
    QModelIndexList range1;
    range1.push_back(model.index(0, 0));
    range1.push_back(model.index(1, 0));
    range1.push_back(model.index(2, 0));
    Sum sumFormula(&model, index1, range1, "=SUM(A1:A3)");

    QModelIndex index2 = model.index(3, 1);
    QModelIndexList range2;
    range1.push_back(model.index(0, 1));
    range1.push_back(model.index(1, 1));
    range1.push_back(model.index(2, 1));
    Max maxFormula(&model, index2, range2, "=MAX(B1:B3)");

    model.removeObserver(&sumFormula);
    ASSERT_EQ(model.countObserver(), 1);

    model.removeObserver(&maxFormula);
    ASSERT_EQ(model.countObserver(), 0);
}

TEST(Model, TestGetObserver) {
    Model model;
    Controller controller(&model);
    View view(&model, &controller);

    QModelIndex index1 = model.index(3, 0);
    QModelIndexList range1;
    range1.push_back(model.index(0, 0));
    range1.push_back(model.index(1, 0));
    range1.push_back(model.index(2, 0));
    Sum sumFormula(&model, index1, range1, "=SUM(A1:A3)");

    QModelIndex index2 = model.index(3, 1);
    QModelIndexList range2;
    range1.push_back(model.index(0, 1));
    range1.push_back(model.index(1, 1));
    range1.push_back(model.index(2, 1));
    Max maxFormula(&model, index2, range2, "=MAX(B1:B3)");

    Observer *observer = model.getObserver();
    ASSERT_EQ(observer, &sumFormula);
    ASSERT_NE(observer, &maxFormula);
}

TEST(Model, TestGetObserverIndex) {
    Model model;
    Controller controller(&model);
    View view(&model, &controller);

    QModelIndex index1 = model.index(3, 0);
    QModelIndexList range1;
    range1.push_back(model.index(0, 0));
    range1.push_back(model.index(1, 0));
    range1.push_back(model.index(2, 0));
    Sum sumFormula(&model, index1, range1, "=SUM(A1:A3)");

    QModelIndex index2 = model.index(3, 1);
    QModelIndexList range2;
    range1.push_back(model.index(0, 1));
    range1.push_back(model.index(1, 1));
    range1.push_back(model.index(2, 1));
    Max maxFormula(&model, index2, range2, "=MAX(B1:B3)");

    Observer *observer = model.getObserver(index2);
    ASSERT_NE(observer, &sumFormula);
    ASSERT_EQ(observer, &maxFormula);
}