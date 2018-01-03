cmake_minimum_required(VERSION 3.9.2)

project(src)


set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -g")
set(SRC ${PROJECT_SOURCE_DIR}/Randomizer/pass.hpp
    ${PROJECT_SOURCE_DIR}/Randomizer/pass.cpp
    )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
add_library(randomizer ${SRC})

