cmake_minimum_required(VERSION 3.10.0)
project(passGen)

#including the headers
include_directories(${PROJECT_SOURCE_DIR}/inc)
find_package(Boost COMPONNENTS system filesystem unit_test_framework REQUIRED)
# ADD THESE INTO NEW CMAKE FILE IN TEST FOLDER
# target_link_libraries(tester
#         ${Boost_FILESYSTEM_LIBRARY}
#         ${Boost_SYSTEM_LIBRARY}
#         ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
#     )
# add_executable(tester test.cpp)
# add_test(tester tester)
#compiler flags
# -lboost_unit_test_framework <- is a compiler flag for boosttestsuit
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -fsanitize=address -g")
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
set(SRC ${PROJECT_SOURCE_DIR}/src/pass.cpp
        ${PROJECT_SOURCE_DIR}/src/main.cpp
)

#creating exe
add_executable(passGen ${SRC})
