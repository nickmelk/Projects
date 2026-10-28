add_executable(
    signal_validator_test
    signal_validator_test.cpp
)

target_link_libraries(
    signal_validator_test
    GTest::gtest_main
)

target_compile_options(
    signal_validator_test
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

include(GoogleTest)
gtest_discover_tests(signal_validator_test)
