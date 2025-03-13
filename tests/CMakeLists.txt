
###
# Dependencies
###

set(Boost_INCLUDE_LIBRARIES math)
set(Boost_ENABLE_CMAKE ON)
set(Boost_USE_MULTITHREADED ON)
# # whether to force the use of the static libraries
# set(Boost_USE_STATIC_LIBS OFF)
# # whether to use libraries linked statically to the C++ runtime ("s" tag)
# set(Boost_USE_STATIC_RUNTIME OFF)
include(FetchContent)
FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.87.0
)
FetchContent_MakeAvailable(Boost)

# tables

add_executable(hash_table_tests tables/hash_table_tests.cpp)
target_link_libraries(hash_table_tests turbo_lib Boost::assert)
add_test(NAME hash_table_tests COMMAND hash_table_tests)

# linked_lists

add_executable(queue_tests linked_lists/queue_tests.cpp)
target_link_libraries(queue_tests turbo_lib)
add_test(NAME queue_tests COMMAND queue_tests)

add_executable(stack_tests linked_lists/stack_tests.cpp)
target_link_libraries(stack_tests turbo_lib)
add_test(NAME stack_tests COMMAND stack_tests)

# oop

add_executable(object_copy_tests oop/object_copy_tests.cpp)
target_link_libraries(object_copy_tests turbo_lib)
add_test(NAME object_copy_tests COMMAND object_copy_tests)

add_executable(polymorphism_tests oop/polymorphism_tests.cpp)
target_link_libraries(polymorphism_tests turbo_lib)
add_test(NAME polymorphism_tests COMMAND polymorphism_tests)

add_executable(singleton_tests oop/singleton_tests.cpp)
target_link_libraries(singleton_tests turbo_lib Boost::assert)
add_test(NAME singleton_tests COMMAND singleton_tests)

# builder

add_executable(builder_pattern_tests oop/builder_pattern_tests.cpp)
target_link_libraries(builder_pattern_tests turbo_lib Boost::assert)
add_test(NAME builder_pattern_tests COMMAND builder_pattern_tests)

# factory

add_executable(factory_tests oop/factory_tests.cpp)
target_link_libraries(factory_tests turbo_lib Boost::assert)
add_test(NAME factory_tests COMMAND factory_tests)

# dependency_injection

add_executable(dependency_injection_tests oop/dependency_injection_tests.cpp)
target_link_libraries(dependency_injection_tests turbo_lib)
add_test(NAME dependency_injection_tests COMMAND dependency_injection_tests)

add_executable(interface_tests oop/interface_tests.cpp)
target_link_libraries(interface_tests turbo_lib)
add_test(NAME interface_tests COMMAND interface_tests)

# multi_threading

add_executable(multi_threading_tests multi_threading/parallelism_tests.cpp)
target_link_libraries(multi_threading_tests turbo_lib)
add_test(NAME multi_threading_tests COMMAND multi_threading_tests)

# fibonacci

add_executable(dynamic_programming_tests dynamic_programming/fibonacci_tests.cpp)
target_link_libraries(dynamic_programming_tests turbo_lib Boost::assert)
add_test(NAME dynamic_programming_tests COMMAND dynamic_programming_tests)

# pointer_arithmetic

add_executable(pointer_arithmetic_tests memory/pointer_arithmetic_tests.cpp)
add_test(NAME pointer_arithmetic_tests COMMAND pointer_arithmetic_tests)

# type_punning

add_executable(type_punning_tests types/type_punning_tests.cpp)
target_link_libraries(type_punning_tests Boost::assert)
add_test(NAME type_punning_tests COMMAND type_punning_tests)
