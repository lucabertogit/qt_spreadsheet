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

// TODO: Impostare fixture

TEST(Max, TestMaxFunction) {
    Model model;
    Controller controller(&model);
    View view(&model, &controller);

    model.item(0, 0)->setText(QString::number(28));
    model.item(1, 0)->setText(QString::number(56));
    model.item(2, 0)->setText(QString::number(37));

    model.item(0, 1)->setText(QString::number(84));
    model.item(1, 1)->setText(QString::number(87));
    model.item(2, 1)->setText(QString::number(12));

    QModelIndex index = model.index(3, 0);

    QModelIndexList range;
    range.push_back(model.index(0, 0));
    range.push_back(model.index(1, 0));
    range.push_back(model.index(2, 0));
    range.push_back(model.index(0, 1));
    range.push_back(model.index(1, 1));
    range.push_back(model.index(2, 1));

    Max max(&model, index, range, "=MAX(A1:B3)");

    ASSERT_EQ(max.getExtendedFormula(), "=MAX(A1:B3)");
    ASSERT_EQ(max.getIndex().row(), 3);
    ASSERT_EQ(max.getIndex().column(), 0);

    QModelIndex trueIndex = model.index(3, 0);
    QModelIndex falseIndex = model.index(4, 2);
    ASSERT_TRUE(max.thereIsFunction(trueIndex));
    ASSERT_FALSE(max.thereIsFunction(falseIndex));
}