cmake_minimum_required(VERSION 3.28)
project(octm CXX)


#[==[==========================================================
                        CMake Config
==========================================================#]==]
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#[==[==========================================================
                        OCTM Lib
==========================================================#]==]
add_library(octm)
target_sources(octm PUBLIC FILE_SET CXX_MODULES FILES   source/octm.cpp
                                                        source/idioms.cpp
                                                        source/const_array.cpp                                                        
                                                        source/bit_scan.cpp
                                                        source/assert.cpp)

target_compile_options(octm PUBLIC -O3 -Wall -fno-exceptions -save-temps -fverbose-asm)


#[==[==========================================================
                    Build Tests
==========================================================#]==]
add_subdirectory(test)
