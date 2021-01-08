set(test_src_list
    ${cxxhippy_SOURCE_DIR}/tests/main.cpp
    ${cxxhippy_SOURCE_DIR}/tests/test_chip.cpp)

add_executable(cxxhippy_tests ${test_src_list})

target_compile_features(cxxhippy_tests PRIVATE cxx_std_17)
target_include_directories(cxxhippy_tests PUBLIC ${cxxhippy_SOURCE_DIR}/include ${cxxhippy_SOURCE_DIR}/extern)
target_link_libraries(cxxhippy_tests PRIVATE cxxhippy_lib fmt::fmt)
