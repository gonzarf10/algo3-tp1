cmake_minimum_required(VERSION 3.25)
project(tp1)

set(CMAKE_CXX_STANDARD 17)

# Dependencia de Google Test
SET(BUILD_GMOCK OFF)
SET(BUILD_GTEST ON)
add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)

# Leemos todos los archivos fuentes en ./src
file(GLOB SOURCE_FILES src/*.cpp src/*.h src/*.hpp)
file(GLOB TESTS tests/*.cpp)

add_executable(correrTests ${SOURCE_FILES} ${TESTS} tablero.h tablero.cpp)

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(correrTests gtest gtest_main)

# Test suites a ejecutar
add_test(correrTests tests_tuki)

add_executable(tp1 main.cpp)
