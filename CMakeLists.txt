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

add_library(table_lib SHARED lib/tables/hash_table.cpp)
add_library(oop_lib SHARED lib/oop/dependency_injection.cpp)
add_library(fibonacci_lib SHARED lib/dynamic_programming/fibonacci.cpp)

add_executable(oop_tests tests/oop_tests.cpp)
target_link_libraries(oop_tests oop_lib)
add_test (NAME oop_tests COMMAND oop_tests)

add_executable(table_tests tests/table_tests.cpp)
target_link_libraries(table_tests table_lib)
add_test (NAME table_tests COMMAND table_tests)

add_executable(fibonacci_tests tests/fibonacci_tests.cpp)
target_link_libraries(fibonacci_tests fibonacci_lib)
add_test (NAME fibonacci_tests COMMAND oop_tests)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
