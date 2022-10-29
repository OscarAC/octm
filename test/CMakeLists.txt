cmake_minimum_required(VERSION 3.7)
project(octm_tests CXX)


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
add_subdirectory(con)





