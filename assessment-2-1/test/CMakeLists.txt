add_executable(
    sigproc_test
    sigproc_test.cpp
)

target_link_libraries(
    sigproc_test
    GTest::gtest_main
)

target_compile_options(
    sigproc_test
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

include(GoogleTest)
gtest_discover_tests(sigproc_test)
