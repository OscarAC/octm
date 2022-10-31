cmake_minimum_required(VERSION 3.7)
project(octm_tests CXX)


if(NOT TARGET octm)
    find_package(octm REQUIRED)
endif()


#[==[==========================================================
                        CTest Config
==========================================================#]==]
include(CTest)

add_library(coverage_config INTERFACE)
option(CODE_COVERAGE "Enable coverage reporting" OFF)
if(CODE_COVERAGE)
    target_compile_options(coverage_config INTERFACE
    -O0        # no optimization
    -g         # generate debug info
    --coverage # sets all required flags
    )
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
        target_link_options(coverage_config INTERFACE --coverage)
    else()
        target_link_libraries(coverage_config INTERFACE --coverage)
    endif()
endif()

enable_testing()

#[==[==========================================================
                        Test Suites
==========================================================#]==]


# Const Array Test
add_executable(test_const_array test_const_array.cpp)
target_link_libraries(test_const_array PRIVATE octm)
target_link_libraries(test_const_array PUBLIC coverage_config)
set_target_properties(test_const_array PROPERTIES COMPILE_FLAGS "--save-temps")
add_test(test__const_array test_const_array)


# Const Map Test
add_executable(test_const_map test_const_map.cpp)
target_link_libraries(test_const_map PRIVATE octm)
target_link_libraries(test_const_map PUBLIC coverage_config)
set_target_properties(test_const_map PROPERTIES COMPILE_FLAGS "--save-temps")
add_test(test__const_map test_const_map)