//
// Created by lucaberto on 24/12/24.
//

#include "gtest/gtest.h"
#include "../src/Model.h"
#include "../src/Controller.h"
#include "../src/View.h"

class MVCSuite : public testing::Test {
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

        item = new QStandardItem(QString::number(64));
        model->setItem(3, 0, item);

        item = new QStandardItem(QString::number(84));
        model->setItem(0, 1, item);

        item = new QStandardItem(QString::number(87));
        model->setItem(1, 1, item);

        item = new QStandardItem(QString::number(12));
        model->setItem(2, 1, item);

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

// TODO: rinominare test
TEST_F(MVCSuite, TestRename) {

}