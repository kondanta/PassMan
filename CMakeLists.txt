cmake_minimum_required(VERSION 3.9.2)
project(passGen)


add_subdirectory(tests)
add_subdirectory(src)


#compiler flags
# -lboost_unit_test_framework <- is a compiler flag for boosttestsuit
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -g")
set(CMAKE_BUILD_TYPE RelWithDebInfo)

# changing compiler
# exports=/usr/bin/[clang/gcc] -> on terminal though [changing environment value]

#Its for the sublime text, without these, it doesnt find the pass.h
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

#set sources -> Better to be explicit
set(SRC
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

#creating exe
add_executable(passGen ${SRC})
target_link_libraries(passGen randomizer)
