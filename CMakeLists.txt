cmake_minimum_required(VERSION 3.28)
project(octm CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(source)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  option(OCTM_BUILD_TESTS "whether or not tests should be built" ON)

  if(OCTM_BUILD_TESTS)
    add_subdirectory(test)
  endif()

endif()
