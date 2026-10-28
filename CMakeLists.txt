cmake_minimum_required(VERSION 3.14)
project(SignalProcessing)

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

add_subdirectory(assessment-2-1/test)
add_subdirectory(assessment-2-2/test)
