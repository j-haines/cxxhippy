cmake_policy(VERSION 3.15..3.17)
cmake_minimum_required(VERSION 3.15...3.17)

project(cxxhippy
	VERSION 0.0.0
	LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	set(CMAKE_CXX_EXTENSIONS OFF)

	include(CTest)
	find_package(Doxygen)
	if(Doxygen_FOUND)
		add_subdirectory(docs)
	else()
		message(STATUS "Doxy not found, not building docs")
	endif()
endif()

include(FetchContent)

FetchContent_Declare(fmtlib
	GIT_REPOSITORY https://github.com/fmtlib/fmt.git
	GIT_TAG master)
FetchContent_MakeAvailable(fmtlib)

add_subdirectory(src)
add_subdirectory(bin)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	add_subdirectory(tests)
endif()
