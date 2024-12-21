cmake_minimum_required(VERSION 3.16)
project(qt_spreadsheet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/lucaberto/Qt/6.7.2/gcc_64/lib/cmake")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6Widgets REQUIRED)

add_executable(qt_spreadsheet main.cpp
        src/Controller.h
        src/Controller.cpp
        src/FactoryFunction.h
        src/FactoryFunction.cpp
        src/Function.h
        src/Function.cpp
        src/MainWindow.h
        src/MainWindow.cpp
        src/Max.h
        src/Max.cpp
        src/Mean.h
        src/Mean.cpp
        src/Min.h
        src/Min.cpp
        src/Model.h
        src/Model.cpp
        src/Observer.h
        src/Subject.h
        src/Sum.h
        src/Sum.cpp
        src/View.h
        src/View.cpp
)

target_link_libraries(qt_spreadsheet Qt6::Widgets)
