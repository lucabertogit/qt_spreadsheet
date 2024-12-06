//
// Created by lucaberto on 06/12/24.
//

#include "gtest/gtest.h"
#include "../CellRange.h"

TEST(CellRange, DefaultCostructor) {
    CellRange range;

    ASSERT_EQ(range.getStartColumn(), 0);
    ASSERT_EQ(range.getStartRow(), 0);
    ASSERT_EQ(range.getEndColumn(), 0);
    ASSERT_EQ(range.getEndRow(), 0);
}

TEST(CellRange, TestSetRange) {
    CellRange range;
    range.setRange("A1:C10");

    ASSERT_EQ(range.getStartColumn(), 0);
    ASSERT_EQ(range.getStartRow(), 0);
    ASSERT_EQ(range.getEndColumn(), 2);
    ASSERT_EQ(range.getEndRow(), 9);

    // TODO: testare in caso di intervalli non validi
}