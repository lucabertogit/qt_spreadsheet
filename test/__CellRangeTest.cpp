//
// Created by lucaberto on 06/12/24.
//

#include "gtest/gtest.h"
#include "../src/CellRange.h"

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

    range.setRange("b2:d8");
    ASSERT_EQ(range.getStartColumn(), 1);
    ASSERT_EQ(range.getStartRow(), 1);
    ASSERT_EQ(range.getEndColumn(), 3);
    ASSERT_EQ(range.getEndRow(), 7);

    range.setRange("C10:A1");
    ASSERT_EQ(range.getStartColumn(), 0);
    ASSERT_EQ(range.getStartRow(), 0);
    ASSERT_EQ(range.getEndColumn(), 2);
    ASSERT_EQ(range.getEndRow(), 9);

    range.setRange("b8:D2");
    ASSERT_EQ(range.getStartColumn(), 1);
    ASSERT_EQ(range.getStartRow(), 1);
    ASSERT_EQ(range.getEndColumn(), 3);
    ASSERT_EQ(range.getEndRow(), 7);
}

TEST(CellRange, TestExceptionRange) { 
    try {
        CellRange range;
        range.setRange("");
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezzione";
    }
    
    try {
        CellRange range;
        range.setRange("A1C10");
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        CellRange range;
        range.setRange("A1;A10");
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        CellRange range;
        range.setRange("A1:");
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        CellRange range;
        range.setRange(":C10");
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        CellRange range;
        range.setRange("?1:C10");
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        CellRange range;
        range.setRange("A1:!10");
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        CellRange range;
        range.setRange("A1;C8:D10");
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }

    try {
        CellRange range;
        range.setRange("A1:C8:D10");
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Intervallo non valido"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }
}
