add_executable(cxxhippy main.cpp)

target_compile_features(cxxhippy PRIVATE cxx_std_17)
target_link_libraries(cxxhippy PRIVATE cxxhippy_lib fmt::fmt)
