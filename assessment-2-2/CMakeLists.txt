cmake_minimum_required(VERSION 3.14)

project(signal_validator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG 063de7e9578f82b369302001269680b4b1553359
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    signal_validator_test
    test/signal_validator_test.cpp
)
target_link_libraries(
    signal_validator_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(signal_validator_test)
