//
// Created by lucaberto on 09/12/24.
//

#include "gtest/gtest.h"
#include "../src/FactoryFunction.h"
#include "../src/Max.h"
#include "../src/Mean.h"
#include "../src/Min.h"
#include "../src/Sum.h"

TEST(FactoryFunction, TestCreateFunction) {
    Model model(10, 10);
    QModelIndex index;
    QModelIndexList indexes;
    std::string formula = "formula";
    FactoryFunction factory;

    Function *function = factory.createFunction(&model, FactoryFunction::CodeFunction::Max, index, indexes, formula);
    ASSERT_EQ(typeid(*function), typeid(Max));
    delete function;

    function = factory.createFunction(&model, FactoryFunction::CodeFunction::Mean, index, indexes, formula);
    ASSERT_EQ(typeid(*function), typeid(Mean));
    delete function;

    function = factory.createFunction(&model, FactoryFunction::CodeFunction::Min, index, indexes, formula);
    ASSERT_EQ(typeid(*function), typeid(Min));
    delete function;

    function = factory.createFunction(&model, FactoryFunction::CodeFunction::Sum, index, indexes, formula);
    ASSERT_EQ(typeid(*function), typeid(Sum));
    delete function;
}