# defines the global project configuration

cmake_minimum_required(VERSION 3.14)
project(InMemoryDB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/googletest)
include_directories(external/googletest/googletest/include)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(main src/main.cpp)