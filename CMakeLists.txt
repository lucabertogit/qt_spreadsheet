cmake_minimum_required(VERSION 3.16)
project(qt_spreadsheet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/lucaberto/Qt/6.7.2/gcc_64/lib/cmake")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6Widgets REQUIRED)

add_executable(qt_spreadsheet main.cpp
        Spreadsheet.h
        Spreadsheet.cpp
        Function.h
        Sum.h
        Sum.cpp
        Max.h
        Max.cpp
        Min.h
        Min.cpp
        Mean.h
        Mean.cpp
        Subject.h
        Observer.h
        Function.cpp
        FactoryFunction.h
        FactoryFunction.cpp
        CellRange.h
        CellRange.cpp
)

target_link_libraries(qt_spreadsheet Qt6::Widgets)
