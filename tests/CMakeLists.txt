# ADD THESE INTO NEW CMAKE FILE IN TEST FOLDER
project(tests)

set(SRC ${PROJECT_SOURCE_DIR}/pass-test.cpp
    )
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/inc
                    ${Boost_INCLUDE_DIRS}
                    )
link_directories(mylib
                ${Boost_LIBRARY_DIR})

add_executable(Test ${SRC})
target_link_libraries(Test mylib)
