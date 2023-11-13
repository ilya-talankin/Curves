cmake_minimum_required(VERSION 3.10)

project(curves LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(
    -Werror
    -Wall
    -Wextra
    -Wpedantic
)

set(SOURCE_LIB
	src/Point.cpp
	src/Vector.cpp
	src/Circle.cpp
	src/Ellipse.cpp
	src/Helix.cpp
)

add_library(curves SHARED ${SOURCE_LIB})

set_target_properties(curves PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
