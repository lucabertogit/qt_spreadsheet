//
// Created by lucaberto on 17/12/24.
//

#include "gtest/gtest.h"
#include "../src/MainWindow.h"

TEST(MainWindow, TestCostructor) {
    Model model(10, 10);
    Controller controller(&model);
    View view(&model, &controller);
    MainWindow window(&view);

    ASSERT_EQ(window.windowTitle(), "Spreadsheet");

    // TODO: eventualmente controllare centralWidget
}