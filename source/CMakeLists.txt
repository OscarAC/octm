add_library(octm)
target_sources(octm PUBLIC FILE_SET CXX_MODULES FILES   octm.cpp
                                                        idioms.cpp
                                                        const_array.cpp                                                        
                                                        bit_scan.cpp
                                                        assert.cpp
                                                        fundamental_holder.cpp)

target_compile_options(octm PUBLIC -O3 -Wall)
