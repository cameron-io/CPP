cmake_minimum_required(VERSION 3.0.0)
project(turbo VERSION 0.1.0 LANGUAGES C CXX)

set(OSBitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()

set(FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBitness}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static_lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}/bin")

include_directories(.)

###
# Libraries
###
add_library(table_lib SHARED
    lib/tables/hash_table.cpp
)
add_library(oop_lib SHARED
    lib/oop/design_patterns/dependency_injection.hpp
    lib/oop/design_patterns/singletons.hpp
    lib/oop/design_patterns/factory.hpp
    lib/oop/object_copy.hpp
)
set_target_properties(oop_lib
    PROPERTIES LINKER_LANGUAGE CXX)
add_library(fibonacci_lib SHARED
    lib/dynamic_programming/fibonacci.hpp
)
set_target_properties(fibonacci_lib
    PROPERTIES LINKER_LANGUAGE CXX)

###
# Executables
###

# Object Oriented Programming

add_executable(dependency_injection_tests
    tests/oop/dependency_injection_tests.cpp)
target_link_libraries(dependency_injection_tests oop_lib)

add_executable(object_copy_tests
tests/oop/object_copy_tests.cpp)
target_link_libraries(object_copy_tests oop_lib)

add_executable(singleton_tests
    tests/oop/singleton_tests.cpp)
target_link_libraries(singleton_tests oop_lib)

add_executable(factory_tests
    tests/oop/factory_tests.cpp)
target_link_libraries(factory_tests oop_lib)

add_test (NAME dependency_injection_tests COMMAND dependency_injection_tests)
add_test (NAME object_copy_tests COMMAND object_copy_tests)
add_test (NAME singleton_tests COMMAND singleton_tests)
add_test (NAME factory_tests COMMAND factory_tests)

# Tables

add_executable(hash_table_tests
    tests/tables/hash_table_tests.cpp)
target_link_libraries(hash_table_tests
    table_lib)
add_test (NAME hash_table_tests COMMAND hash_table_tests)

# Dynamic Programming

add_executable(dynamic_programming_tests
    tests/dynamic_programming/fibonacci_tests.cpp)
target_link_libraries(dynamic_programming_tests
    fibonacci_lib)
add_test (
    NAME dynamic_programming_tests 
    COMMAND dynamic_programming_tests)

###
# CTest
###

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
