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

    range.setRange("a1:c10");

    range.setRange("C10:A1");

    range.setRange("A10:C1");

    range.setRange("A1:C8:D10");
}

TEST(CellRange, TestExceptionRange) {
    CellRange range;
    
    try {
        range.setRange("");
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }
    
    try {
        range.setRange("A1C10");
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        range.setRange("A1;A10");
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        range.setRange("A1:");
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        range.setRange(":C10");
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        range.setRange("?1:C10");
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        range.setRange("A1:!10");
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    range.setRange("A1;C8:D10");
}
