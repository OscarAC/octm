if(NOT TARGET octm)
    find_package(octm REQUIRED)
endif()

include(CTest)

add_library(octm_coverage_config INTERFACE)
option(CODE_COVERAGE "Enable coverage reporting" OFF)
if(CODE_COVERAGE)
    target_compile_options(octm_coverage_config INTERFACE
    -O0        # no optimization
    -g         # generate debug info
    --coverage # sets all required flags
    )
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
        target_link_options(octm_coverage_config INTERFACE --coverage)
    else()
        target_link_libraries(octm_coverage_config INTERFACE --coverage)
    endif()
endif()

enable_testing()

function (add_test_file TEST_NAME TEST_FILE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} PUBLIC octm octm_coverage_config)
    add_test(${TEST_NAME}_ ${TEST_NAME})
endfunction()

file(GLOB testfiles "${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp")
foreach(file ${testfiles})
    get_filename_component(filename ${file} NAME)
    string(REGEX REPLACE "\\.[^.]*$" "" testname ${filename})
    add_test_file(${testname} ${filename})        
endforeach()
