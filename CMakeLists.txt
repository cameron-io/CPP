cmake_minimum_required(VERSION 3.0.0)
project(turbo VERSION 0.1.0 LANGUAGES C CXX)

set(OSBitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()

set(FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBitness}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static_lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

include_directories(.)

###
# Libraries
###
add_library(table_lib SHARED lib/tables/hash_table.cpp)
add_library(oop_lib SHARED
    lib/oop/dependency_injection.cpp
    lib/oop/object_copy.hpp
    lib/oop/singletons.hpp
)
add_library(fibonacci_lib SHARED lib/dynamic_programming/fibonacci.cpp)

###
# Executables
###

add_executable(oop_tests
    tests/oop/dep_injection_tests.cpp
    tests/oop/object_copy_tests.cpp
    tests/oop/singleton_tests.cpp)
target_link_libraries(oop_tests
    oop_lib)
add_test (NAME oop_tests COMMAND oop_tests)

add_executable(table_tests
    tests/tables/hash_table_tests.cpp)
target_link_libraries(table_tests
    table_lib)
add_test (NAME table_tests COMMAND table_tests)

add_executable(dynamic_programming_tests
    tests/dynamic_programming/fibonacci_tests.cpp)
target_link_libraries(dynamic_programming_tests
    fibonacci_lib)
add_test (NAME dynamic_programming_tests COMMAND dynamic_programming_tests)

###
# CTest
###

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
