//
// Created by lucaberto on 06/12/24.
//

#include "gtest/gtest.h"
#include "../CellRange.h"

class CellRangeSuite : public ::testing::Test {
protected:
    virtual void setUp() {
        range.setRange("A1:C10");
    }
    CellRange range;
};

TEST_F(CellRangeSuite, TestCellRange) {
    range.setStartColumn(1);
    ASSERT_EQ(range.getStartColumn(), 1);

    range.setStartRow(1);
    ASSERT_EQ(range.getStartRow(), 1);

    range.setEndColumn(2);
    ASSERT_EQ(range.getEndColumn(), 2);

    range.setEndRow(8);
    ASSERT_EQ(range.getEndRow(), 8);
}