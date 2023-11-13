cmake_minimum_required(VERSION 3.10)

project(curves_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(
    -Werror
    -Wall
    -Wextra
    -Wpedantic

    -fopenmp
)

add_subdirectory(curves)

find_package(OpenMP REQUIRED)

add_executable(
    curves_example
    main.cpp
    curves_generator/RandomCurveGenerator.cpp
)

set_target_properties(curves_example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

target_link_libraries(curves_example curves OpenMP::OpenMP_CXX)
