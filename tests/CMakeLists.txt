# defines how to build and link the test target

add_executable(runTests test_main.cpp test_database.cpp)
target_link_libraries(runTests gtest gtest_main pthread)
