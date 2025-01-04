cmake_minimum_required(VERSION 3.16)

set(CMAKE_PREFIX_PATH "/home/lucaberto/Qt/6.7.2/gcc_64/lib/cmake")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Test Widgets)

qt_standard_project_setup()

set(PROJECT_SOURCES ../src/FactoryFunction.cpp
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
        ../src/Subject.h
        ../src/Sum.cpp
        ../src/Sum.h
        ../src/Controller.h
        ../src/Controller.cpp
        ../src/View.h
        ../src/View.cpp
        ../src/Model.h
        ../src/Model.cpp
        ../src/MainWindow.h
        ../src/MainWindow.cpp
)

qt_add_executable(runQtSpreadsheetGuiTests
        TestGui.cpp
        ${PROJECT_SOURCES}
)

target_link_libraries(runQtSpreadsheetGuiTests PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Test
        Qt6::Widgets
)

install(TARGETS runQtSpreadsheetGuiTests
        BUNDLE DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
        TARGET runQtSpreadsheetGuiTests
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})