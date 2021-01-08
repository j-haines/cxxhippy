set(header_list
    ${cxxhippy_SOURCE_DIR}/include/chip.hpp
    ${cxxhippy_SOURCE_DIR}/include/disassembler.hpp
    ${cxxhippy_SOURCE_DIR}/include/files.hpp
    ${cxxhippy_SOURCE_DIR}/include/mem.hpp)
set(src_list
    ${cxxhippy_SOURCE_DIR}/src/chip.cpp
    ${cxxhippy_SOURCE_DIR}/src/disassembler.cpp
    ${cxxhippy_SOURCE_DIR}/src/mem.cpp)

add_library(cxxhippy_lib ${src_list} ${header_list})

target_compile_features(cxxhippy_lib PRIVATE cxx_std_17)
target_include_directories(cxxhippy_lib PUBLIC ${cxxhippy_SOURCE_DIR}/include)
target_link_libraries(cxxhippy_lib PRIVATE fmt::fmt)
