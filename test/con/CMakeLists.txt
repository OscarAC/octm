cmake_minimum_required(VERSION 3.7)
project(octm_tests CXX)

if(NOT TARGET octm)
    find_package(octm REQUIRED)
endif()

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

# Const Map Test
add_executable(test_pair test_pair.cpp)
target_link_libraries(test_pair PRIVATE octm)
target_link_libraries(test_pair PUBLIC coverage_config)
set_target_properties(test_pair PROPERTIES COMPILE_FLAGS "--save-temps")
add_test(test__pair test_pair)