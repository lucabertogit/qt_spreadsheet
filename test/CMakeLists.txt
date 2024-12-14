cmake_minimum_required(VERSION 3.16)

enable_testing()
set(GOOGLETEST_VERSION 1.15.2)
add_subdirectory(../lib/googletest googletest)
include_directories(../lib/googletest/include)

file(GLOB TEST_SOURCES *.cpp)

set(PROJECT_SOURCES ../src/CellRange.cpp
        ../src/CellRange.h
        ../src/FactoryFunction.cpp
        ../src/FactoryFunction.h
        ../src/Function.cpp
        ../src/Function.h
        ../src/Max.cpp
        ../src/Max.h
        ../src/Mean.cpp
        ../src/Mean.h
        ../src/Min.cpp
        ../src/Min.h
        ../src/Observer.h
        ../src/Spreadsheet.cpp
        ../src/Spreadsheet.h
        ../src/Subject.h
        ../src/Sum.cpp
        ../src/Sum.h
        ../src/Controller.h
        ../src/Controller.cpp
)

add_executable(runQtSpreadsheetTests ${TEST_SOURCES} ${PROJECT_SOURCES})

target_link_libraries(runQtSpreadsheetTests gtest gtest_main Qt6::Widgets)

add_test(NAME StSpreadsheetTest COMMAND runQtSpreadsheetTests)