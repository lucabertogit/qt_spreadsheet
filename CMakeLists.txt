cmake_minimum_required(VERSION 3.16)
project(qt_spreadsheet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/lucaberto/Qt/6.7.2/gcc_64/lib/cmake")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

set(SOURCES src/FactoryFunction.cpp
        src/Function.cpp
        src/Sum.cpp
        src/Max.cpp
        src/Min.cpp
        src/Mean.cpp
        src/Controller.cpp
        src/View.cpp
        src/Model.cpp
        src/MainWindow.cpp
)

set(HEADERS src/FactoryFunction.h
        src/Function.h
        src/Observer.h
        src/Subject.h
        src/Sum.h
        src/Max.h
        src/Min.h
        src/Mean.h
        src/Controller.h
        src/View.h
        src/Model.h
        src/MainWindow.h
)

add_executable(qt_spreadsheet main.cpp ${SOURCES} ${HEADERS})

target_link_libraries(qt_spreadsheet Qt6::Gui Qt6::Widgets)

add_subdirectory(test)
