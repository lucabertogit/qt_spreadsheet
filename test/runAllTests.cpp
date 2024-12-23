//
// Created by lucaberto on 29/11/24.
//

#include <QApplication>

#include "gtest/gtest.h"

// TODO: creare MVCFixture che simula l'utilizzo dell'interfaccia (vedi FunctionFixture)
// TODO: creare eventualmente MVCTest (esempio test su formula)
int main(int argc, char **argv) {
    QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
