cmake_minimum_required(VERSION 3.16)
project(qt_spreadsheet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/lucaberto/Qt/6.7.2/gcc_64/lib/cmake")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6Widgets REQUIRED)

add_subdirectory(test)
set(SOURCE_FILES CellRange.h
        CellRange.cpp
        FactoryFunction.h
        FactoryFunction.cpp
        Function.h
        Function.cpp
        Observer.h
        Subject.h
        Sum.h
        Sum.cpp
        Max.h
        Max.cpp
        Min.h
        Min.cpp
        Mean.h
        Mean.cpp
)

add_executable(qt_spreadsheet main.cpp
        Spreadsheet.h
        Spreadsheet.cpp
)

add_library(core ${SOURCE_FILES})

target_link_libraries(qt_spreadsheet Qt6::Widgets core)
