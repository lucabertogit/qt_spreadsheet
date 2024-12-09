//
// Created by lucaberto on 29/11/24.
//

#include <QApplication>

#include "gtest/gtest.h"

int main(int argc, char **argv) {
    QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
