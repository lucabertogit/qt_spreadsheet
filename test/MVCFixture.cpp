//
// Created by lucaberto on 24/12/24.
//

#include "gtest/gtest.h"
#include <QLineEdit>
#include "../src/Model.h"
#include "../src/Controller.h"
#include "../src/View.h"

class MVCSuite : public testing::Test {
protected:
    void SetUp() override {
        model = new Model;
        controller = new Controller(model);
        view = new View(model, controller);

        QLineEdit *editor = new QLineEdit;
        editor->setText(QString::number(28));
        QModelIndex index = model->index(0, 0);
        view->setIndexWidget(index, editor);
        QStandardItem *item = new QStandardItem(QString::number(28));
        model->setItem(0, 0, item);

        editor = new QLineEdit;
        editor->setText(QString::number(56));
        index = model->index(1, 0);
        view->setIndexWidget(index, editor);
        item = new QStandardItem(QString::number(56));
        model->setItem(1, 0, item);

        editor = new QLineEdit;
        editor->setText(QString::number(27));
        index = model->index(2, 0);
        view->setIndexWidget(index, editor);
        item = new QStandardItem(QString::number(27));
        model->setItem(2, 0, item);

        editor = new QLineEdit;
        editor->setText(QString::number(64));
        index = model->index(3, 0);
        view->setIndexWidget(index, editor);
        item = new QStandardItem(QString::number(64));
        model->setItem(3, 0, item);

        editor = new QLineEdit;
        editor->setText(QString::number(84));
        index = model->index(0, 1);
        view->setIndexWidget(index, editor);
        item = new QStandardItem(QString::number(84));
        model->setItem(0, 1, item);

        editor = new QLineEdit;
        editor->setText(QString::number(87));
        index = model->index(1, 1);
        view->setIndexWidget(index, editor);
        item = new QStandardItem(QString::number(87));
        model->setItem(1, 1, item);

        editor = new QLineEdit;
        editor->setText(QString::number(12));
        index = model->index(2, 1);
        view->setIndexWidget(index, editor);
        item = new QStandardItem(QString::number(12));
        model->setItem(2, 1, item);

        editor = new QLineEdit;
        editor->setText(QString::number(74));
        index = model->index(3, 1);
        view->setIndexWidget(index, editor);
        item = new QStandardItem(QString::number(74));
        model->setItem(3, 1, item);
    }

    void TearDown() override {
        delete view;
        delete controller;
        delete model;
    }

    Model *model;
    Controller *controller;
    View *view;
};

class MVCSuiteString : public testing::Test {
protected:
    void SetUp() override {
        model = new Model;
        controller = new Controller(model);
        view = new View(model, controller);

        QLineEdit *editor = new QLineEdit;
        editor->setText("string");
        QModelIndex index = model->index(0, 0);
        view->setIndexWidget(index, editor);
        QStandardItem *item = new QStandardItem("string");
        model->setItem(0, 0, item);

        editor = new QLineEdit;
        editor->setText("string");
        index = model->index(1, 0);
        view->setIndexWidget(index, editor);
        item = new QStandardItem("string");
        model->setItem(1, 0, item);

        editor = new QLineEdit;
        editor->setText("string");
        index = model->index(2, 0);
        view->setIndexWidget(index, editor);
        item = new QStandardItem("string");
        model->setItem(2, 0, item);

        editor = new QLineEdit;
        editor->setText("string");
        index = model->index(3, 0);
        view->setIndexWidget(index, editor);
        item = new QStandardItem("string");
        model->setItem(3, 0, item);

        editor = new QLineEdit;
        editor->setText("string");
        index = model->index(0, 1);
        view->setIndexWidget(index, editor);
        item = new QStandardItem("string");
        model->setItem(0, 1, item);

        editor = new QLineEdit;
        editor->setText("string");
        index = model->index(1, 1);
        view->setIndexWidget(index, editor);
        item = new QStandardItem("string");
        model->setItem(1, 1, item);

        editor = new QLineEdit;
        editor->setText("string");
        index = model->index(2, 1);
        view->setIndexWidget(index, editor);
        item = new QStandardItem("string");
        model->setItem(2, 1, item);

        editor = new QLineEdit;
        editor->setText("string");
        index = model->index(3, 1);
        view->setIndexWidget(index, editor);
        item = new QStandardItem("string");
        model->setItem(3, 1, item);
    }

    void TearDown() override {
        delete view;
        delete controller;
        delete model;
    }

    Model *model;
    Controller *controller;
    View *view;
};

TEST_F(MVCSuite, TestGUI) {
    ASSERT_EQ(model->item(0, 0)->text(), QString::number(28));
    ASSERT_EQ(model->item(1, 0)->text(), QString::number(56));
    ASSERT_EQ(model->item(2, 0)->text(), QString::number(27));
    ASSERT_EQ(model->item(3, 0)->text(), QString::number(64));
    ASSERT_EQ(model->item(0, 1)->text(), QString::number(84));
    ASSERT_EQ(model->item(1, 1)->text(), QString::number(87));
    ASSERT_EQ(model->item(2, 1)->text(), QString::number(12));
    ASSERT_EQ(model->item(3, 1)->text(), QString::number(74));
    QModelIndex currIndex = model->index(0, 0);
    QLineEdit *editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), QString::number(28));
    currIndex = model->index(1, 0);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), QString::number(56));
    currIndex = model->index(2, 0);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), QString::number(27));
    currIndex = model->index(3, 0);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), QString::number(64));
    currIndex = model->index(0, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), QString::number(84));
    currIndex = model->index(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), QString::number(87));
    currIndex = model->index(2, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), QString::number(12));
    currIndex = model->index(3, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), QString::number(74));


    // inserimento formula MAX
    currIndex = model->index(4, 0);
    view->setCurrentIndex(currIndex);
    QStandardItem *item = new QStandardItem;
    model->setItem(4, 0, item);
    editor = new QLineEdit;
    editor->setText("=MAX(A1:B4)");
    controller->execute(currIndex, editor);
    item->setText("=MAX(A1:B4)");
    view->setIndexWidget(currIndex, editor);
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(87));

    // inserimento formula MEAN
    currIndex = model->index(4, 1);
    view->setCurrentIndex(currIndex);
    item = new QStandardItem;
    model->setItem(4, 1, item);
    editor = new QLineEdit;
    editor->setText("=MEAN(A1:B4)");
    controller->execute(currIndex, editor);
    item->setText("=MEAN(A1:B4)");
    view->setIndexWidget(currIndex, editor);
    ASSERT_EQ(model->item(4, 1)->text(), QString::number(54));

    // inserimento formula MIN
    currIndex = model->index(4, 2);
    view->setCurrentIndex(currIndex);
    item = new QStandardItem;
    model->setItem(4, 2, item);
    editor = new QLineEdit;
    editor->setText("=MIN(A1:B4)");
    controller->execute(currIndex, editor);
    item->setText("=MIN(A1:B4)");
    view->setIndexWidget(currIndex, editor);
    ASSERT_EQ(model->item(4, 2)->text(), QString::number(12));

    // inserimento formula SUM
    currIndex = model->index(4, 3);
    view->setCurrentIndex(currIndex);
    item = new QStandardItem;
    model->setItem(4, 3, item);
    editor = new QLineEdit;
    editor->setText("=SUM(A1:B4)");
    controller->execute(currIndex, editor);
    item->setText("=SUM(A1:B4)");
    view->setIndexWidget(currIndex, editor);
    ASSERT_EQ(model->item(4, 3)->text(), QString::number(432));

    // modifica valore cella dentro formula
    currIndex = model->index(1, 1);
    view->setCurrentIndex(currIndex);
    item = model->item(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText(QString::number(2));
    controller->execute(currIndex, editor);
    item->setText(QString::number(2));
    ASSERT_EQ(model->item(1, 1)->text(), QString::number(2));
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(84));
    ASSERT_EQ(model->item(4, 1)->text(), QString::number(43.375));
    ASSERT_EQ(model->item(4, 2)->text(), QString::number(2));
    ASSERT_EQ(model->item(4, 3)->text(), QString::number(347));

    // modifica valore cella dentro formula con valore string
    currIndex = model->index(1, 1);
    view->setCurrentIndex(currIndex);
    item = model->item(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText("string");
    controller->execute(currIndex, editor);
    item->setText("string");
    ASSERT_EQ(model->item(1, 1)->text(), "string");
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(84));
    ASSERT_EQ(model->item(4, 1)->text(), QString::number(49.285714286));
    ASSERT_EQ(model->item(4, 2)->text(), QString::number(12));
    ASSERT_EQ(model->item(4, 3)->text(), QString::number(345));

    // modifica formula
    currIndex = model->index(4, 3);
    view->setCurrentIndex(currIndex);
    item = model->item(4, 3);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText("=MEAN(A1:B1)");
    controller->execute(currIndex, editor);
    item->setText("=MEAN(A1:B1)");
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(84));
    ASSERT_EQ(model->item(4, 1)->text(), QString::number(49.285714286));
    ASSERT_EQ(model->item(4, 2)->text(), QString::number(12));
    ASSERT_EQ(model->item(4, 3)->text(), QString::number(56));

    // modificare formula con valore
    currIndex = model->index(4, 3);
    view->setCurrentIndex(currIndex);
    item = model->item(4, 3);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText("string");
    controller->execute(currIndex, editor);
    item->setText("string");
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(84));
    ASSERT_EQ(model->item(4, 1)->text(), QString::number(49.285714286));
    ASSERT_EQ(model->item(4, 2)->text(), QString::number(12));
    ASSERT_EQ(model->item(4, 3)->text(), "string");

    // ripristinare formula
    currIndex = model->index(4, 3);
    view->setCurrentIndex(currIndex);
    item = model->item(4, 3);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText("=MEAN(A1:B1)");
    controller->execute(currIndex, editor);
    item->setText("=MEAN(A1:B1)");
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(84));
    ASSERT_EQ(model->item(4, 1)->text(), QString::number(49.285714286));
    ASSERT_EQ(model->item(4, 2)->text(), QString::number(12));
    ASSERT_EQ(model->item(4, 3)->text(), QString::number(56));

    // cancellare formula
    currIndex = model->index(4, 3);
    view->setCurrentIndex(currIndex);
    item = model->item(4, 3);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText(QString());
    controller->execute(currIndex, editor);
    item->setText(QString());
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(84));
    ASSERT_EQ(model->item(4, 1)->text(), QString::number(49.285714286));
    ASSERT_EQ(model->item(4, 2)->text(), QString::number(12));
    ASSERT_TRUE(model->item(4, 3)->text().isEmpty());
}

TEST_F(MVCSuiteString, TestFunctionWithValueString) {
    ASSERT_EQ(model->item(0, 0)->text(), "string");
    ASSERT_EQ(model->item(1, 0)->text(), "string");
    ASSERT_EQ(model->item(2, 0)->text(), "string");
    ASSERT_EQ(model->item(3, 0)->text(), "string");
    ASSERT_EQ(model->item(0, 1)->text(), "string");
    ASSERT_EQ(model->item(1, 1)->text(), "string");
    ASSERT_EQ(model->item(2, 1)->text(), "string");
    ASSERT_EQ(model->item(3, 1)->text(), "string");
    QModelIndex currIndex = model->index(0, 0);
    QLineEdit *editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), "string");
    currIndex = model->index(1, 0);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), "string");
    currIndex = model->index(2, 0);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), "string");
    currIndex = model->index(3, 0);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), "string");
    currIndex = model->index(0, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), "string");
    currIndex = model->index(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), "string");
    currIndex = model->index(2, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), "string");
    currIndex = model->index(3, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    ASSERT_EQ(editor->text(), "string");

    // inserimento formula MAX
    currIndex = model->index(4, 0);
    view->setCurrentIndex(currIndex);
    QStandardItem *item = new QStandardItem;
    model->setItem(4, 0, item);
    editor = new QLineEdit;
    editor->setText("=MAX(A1:B4)");
    controller->execute(currIndex, editor);
    item->setText("=MAX(A1:B4)");
    view->setIndexWidget(currIndex, editor);
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(0));

    // mettere un valore
    currIndex = model->index(1, 1);
    view->setCurrentIndex(currIndex);
    item = model->item(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText(QString::number(2));
    controller->execute(currIndex, editor);
    item->setText(QString::number(2));
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(2));

    // ripristinare string
    currIndex = model->index(1, 1);
    view->setCurrentIndex(currIndex);
    item = model->item(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText("string");
    controller->execute(currIndex, editor);
    item->setText("string");
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(0));

    // inserimento formula MIN
    currIndex = model->index(4, 0);
    view->setCurrentIndex(currIndex);
    item = new QStandardItem;
    model->setItem(4, 0, item);
    editor = new QLineEdit;
    editor->setText("=MIN(A1:B4)");
    controller->execute(currIndex, editor);
    item->setText("=MIN(A1:B4)");
    view->setIndexWidget(currIndex, editor);
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(0));

    // mettere un valore
    currIndex = model->index(1, 1);
    view->setCurrentIndex(currIndex);
    item = model->item(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText(QString::number(2));
    controller->execute(currIndex, editor);
    item->setText(QString::number(2));
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(2));

    // ripristinare string
    currIndex = model->index(1, 1);
    view->setCurrentIndex(currIndex);
    item = model->item(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText("string");
    controller->execute(currIndex, editor);
    item->setText("string");
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(0));

    // inserimento formula MEAN
    currIndex = model->index(4, 0);
    view->setCurrentIndex(currIndex);
    item = new QStandardItem;
    model->setItem(4, 0, item);
    editor = new QLineEdit;
    editor->setText("=MEAN(A1:B4)");
    controller->execute(currIndex, editor);
    item->setText("=MEAN(A1:B4)");
    view->setIndexWidget(currIndex, editor);
    ASSERT_EQ(model->item(4, 0)->text(), "#DIV/0!");

    // mettere un valore
    currIndex = model->index(1, 1);
    view->setCurrentIndex(currIndex);
    item = model->item(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText(QString::number(2));
    controller->execute(currIndex, editor);
    item->setText(QString::number(2));
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(2));

    // ripristinare string
    currIndex = model->index(1, 1);
    view->setCurrentIndex(currIndex);
    item = model->item(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText("string");
    controller->execute(currIndex, editor);
    item->setText("string");
    ASSERT_EQ(model->item(4, 0)->text(), "#DIV/0!");

    // inserimento formula SUM
    currIndex = model->index(4, 0);
    view->setCurrentIndex(currIndex);
    item = new QStandardItem;
    model->setItem(4, 0, item);
    editor = new QLineEdit;
    editor->setText("=SUM(A1:B4)");
    controller->execute(currIndex, editor);
    item->setText("=SUM(A1:B4)");
    view->setIndexWidget(currIndex, editor);
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(0));

    // mettere un valore
    currIndex = model->index(1, 1);
    view->setCurrentIndex(currIndex);
    item = model->item(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText(QString::number(2));
    controller->execute(currIndex, editor);
    item->setText(QString::number(2));
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(2));

    // ripristinare string
    currIndex = model->index(1, 1);
    view->setCurrentIndex(currIndex);
    item = model->item(1, 1);
    editor = qobject_cast<QLineEdit *>(view->indexWidget(currIndex));
    editor->setText("string");
    controller->execute(currIndex, editor);
    item->setText("string");
    ASSERT_EQ(model->item(4, 0)->text(), QString::number(0));
}