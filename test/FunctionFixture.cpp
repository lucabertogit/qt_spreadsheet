//
// Created by lucaberto on 22/12/24.
//

#include "gtest/gtest.h"
#include "../src/Max.h"
#include "../src/Mean.h"
#include "../src/Min.h"
#include "../src/Sum.h"
#include "../src/Controller.h"
#include "../src/View.h"

class FunctionSuite: public testing::Test {
protected:
    void SetUp() override {
        model = new Model;
        controller = new Controller(model);
        view = new View(model, controller);

        QStandardItem *item = new QStandardItem(QString::number(28));
        model->setItem(0, 0, item);

        item = new QStandardItem(QString::number(56));
        model->setItem(1, 0, item);

        item = new QStandardItem(QString::number(27));
        model->setItem(2, 0, item);

        item = new QStandardItem(QString::number(84));
        model->setItem(0, 1, item);

        item = new QStandardItem(QString::number(87));
        model->setItem(1, 1, item);

        item = new QStandardItem(QString::number(12));
        model->setItem(2, 1, item);

        QModelIndex maxIndex = model->index(3, 0);
        QModelIndex meanIndex = model->index(3, 1);
        QModelIndex minIndex = model->index(3, 2);
        QModelIndex sumIndex = model->index(3, 3);

        QModelIndexList range;
        range.push_back(model->index(0, 0));
        range.push_back(model->index(1, 0));
        range.push_back(model->index(2, 0));
        range.push_back(model->index(0, 1));
        range.push_back(model->index(1, 1));
        range.push_back(model->index(2, 1));

        item = new QStandardItem(QString("=MAX(A1:B3)"));
        model->setItem(3, 0, item);
        max = new Max(model, maxIndex, range, "=MAX(A1:B3)");

        item = new QStandardItem(QString("=MEAN(A1:B3)"));
        model->setItem(3, 1, item);
        mean = new Mean(model, meanIndex, range, "=MEAN(A1:B3)");

        item = new QStandardItem(QString("=MIN(A1:B3)"));
        model->setItem(3, 2, item);
        min = new Min(model, minIndex, range, "=MIN(A1:B3)");

        item = new QStandardItem(QString("=SUM(A1:B3)"));
        model->setItem(3, 3, item);
        sum = new Sum(model, sumIndex, range, "=SUM(A1:B3)");

        trueIndex = model->index(3, 0);
        falseIndex = model->index(4, 2);
    }

    void TearDown() override {
        delete sum;
        delete min;
        delete mean;
        delete max;
        delete view;
        delete controller;
        delete model;
    }

    Model *model;
    Controller *controller;
    View *view;
    Max *max;
    Mean *mean;
    Min *min;
    Sum *sum;
    QModelIndex trueIndex;
    QModelIndex falseIndex;
};

TEST_F(FunctionSuite, TestMaxFunction) {
    ASSERT_EQ(model->countObserver(), 4);
    ASSERT_EQ(max->getExtendedFormula(), "=MAX(A1:B3)");
    ASSERT_EQ(max->getIndex().row(), 3);
    ASSERT_EQ(max->getIndex().column(), 0);
    ASSERT_TRUE(max->thereIsFunction(trueIndex));
    ASSERT_FALSE(max->thereIsFunction(falseIndex));

    max->compute();
    ASSERT_EQ(model->item(3, 0)->text(), QString::number(87));
}

// TODO: modificare riferimenti
TEST_F(FunctionSuite, TestMeanFunction) {
    ASSERT_EQ(model->countObserver(), 4);
    ASSERT_EQ(max->getExtendedFormula(), "=MAX(A1:B3)");
    ASSERT_EQ(max->getIndex().row(), 3);
    ASSERT_EQ(max->getIndex().column(), 0);
    ASSERT_TRUE(max->thereIsFunction(trueIndex));
    ASSERT_FALSE(max->thereIsFunction(falseIndex));

    max->compute();
    ASSERT_EQ(model->item(3, 0)->text(), QString::number(87));
}

// TODO: modificare riferimenti
TEST_F(FunctionSuite, TestMinFunction) {
    ASSERT_EQ(model->countObserver(), 4);
    ASSERT_EQ(max->getExtendedFormula(), "=MAX(A1:B3)");
    ASSERT_EQ(max->getIndex().row(), 3);
    ASSERT_EQ(max->getIndex().column(), 0);
    ASSERT_TRUE(max->thereIsFunction(trueIndex));
    ASSERT_FALSE(max->thereIsFunction(falseIndex));

    max->compute();
    ASSERT_EQ(model->item(3, 0)->text(), QString::number(87));
}

// TODO: modificare riferimenti
TEST_F(FunctionSuite, TestSumFunction) {
    ASSERT_EQ(model->countObserver(), 4);
    ASSERT_EQ(max->getExtendedFormula(), "=MAX(A1:B3)");
    ASSERT_EQ(max->getIndex().row(), 3);
    ASSERT_EQ(max->getIndex().column(), 0);
    ASSERT_TRUE(max->thereIsFunction(trueIndex));
    ASSERT_FALSE(max->thereIsFunction(falseIndex));

    max->compute();
    ASSERT_EQ(model->item(3, 0)->text(), QString::number(87));
}