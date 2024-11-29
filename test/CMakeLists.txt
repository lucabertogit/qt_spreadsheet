cmake_minimum_required(VERSION 3.16)

set(GOOGLETEST_VERSION 1.15.2)
add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR ./lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp)
add_executable(runQtSpreadsheetTests ${TEST_SOURCE_FILES})
target_link_libraries(runQtSpreadsheetTests gtest gtest_main core)