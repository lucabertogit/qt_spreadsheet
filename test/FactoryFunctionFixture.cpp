//
// Created by lucaberto on 09/12/24.
//

#include "gtest/gtest.h"
#include "../src/FactoryFunction.h"

class FactoryFunctionSuite : public ::testing::Test {
protected:
    virtual void setUp() {
        range.setRange("A1:A10");
    }
    Spreadsheet sheet;
    FactoryFunction factory;
    CellRange range;
    Function *function;
};

TEST_F(FactoryFunctionSuite, TestCreateFunction) {
    function = factory.createFunction(&sheet, "SUM", range);
    ASSERT_EQ(typeid(*function), typeid(Sum));
    delete function;

    function = factory.createFunction(&sheet, "MAX", range);
    ASSERT_EQ(typeid(*function), typeid(Max));
    delete function;

    function = factory.createFunction(&sheet, "MIN", range);
    ASSERT_EQ(typeid(*function), typeid(Min));
    delete function;

    function = factory.createFunction(&sheet, "MEAN", range);
    ASSERT_EQ(typeid(*function), typeid(Mean));
    delete function;

    try {
        function = factory.createFunction(&sheet, "ALTRO", range);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Funzione non valida"));
    } catch (...) {
        FAIL() << "Lanciata altra eccesione";
    }
}