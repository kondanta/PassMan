cmake_minimum_required(VERSION 3.10.0)
project(passGen)

#including the headers
include_directories(${PROJECT_SOURCE_DIR}/inc)


add_subdirectory(tests)


add_library(mylib SHARED ${PROJECT_SOURCE_DIR}/src/pass.cpp)

#compiler flags
# -lboost_unit_test_framework <- is a compiler flag for boosttestsuit
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -g")
set(CMAKE_BUILD_TYPE RelWithDebInfo)

# changing compiler
# exports=/usr/bin/[clang/gcc] -> on terminal though [changing environment value]

#Its for the sublime text, without these, it doesnt find the pass.h
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )

#IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
#  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
#    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
#    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
#  )
#ENDIF()


#set sources -> Better to be explicit
set(SRC
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

#creating exe
add_executable(passGen ${SRC})
target_link_libraries(passGen mylib)
