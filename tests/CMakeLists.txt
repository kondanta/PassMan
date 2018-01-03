cmake_minimum_required(VERSION 3.10.0)

# ADD THESE INTO NEW CMAKE FILE IN TEST FOLDER
project(tests)

set(SRC ${PROJECT_SOURCE_DIR}/pass-test.cpp
    )


set(CMAKE_CXX_FLAGS "-std=c++17 -g -O3 -Wall -Wextra -lgtest")  
add_executable(Test ${SRC})
target_link_libraries(Test randomizer)
