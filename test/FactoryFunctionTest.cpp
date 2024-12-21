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
    Model model;
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

TEST(FactoryFunction, TestCodeFromString) {
    FactoryFunction factory;

    std::string codeFunction = "MAX";
    FactoryFunction::CodeFunction code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Max);

    codeFunction = "max";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Max);

    codeFunction = "mAX";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Max);

    codeFunction = "MEAN";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Mean);

    codeFunction = "mean";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Mean);

    codeFunction = "Mean";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Mean);

    codeFunction = "MIN";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Min);

    codeFunction = "min";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Min);

    codeFunction = "MiN";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Min);

    codeFunction = "SUM";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Sum);

    codeFunction = "sum";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Sum);

    codeFunction = "sUm";
    code = factory.codeFromString(codeFunction);
    ASSERT_EQ(code, FactoryFunction::CodeFunction::Sum);

    try {
        codeFunction = "SOMMA";
        code = factory.codeFromString(codeFunction);
        FAIL() << "Nessuna eccezione lanciata";
    } catch (std::invalid_argument &e) {
        ASSERT_EQ(e.what(), std::string("Codice funzione non disponibile"));
    } catch (...) {
        FAIL() << "Lanciata altra eccezione";
    }
}