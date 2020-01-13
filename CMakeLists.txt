cmake_minimum_required(VERSION 3.5)

project(main)

set(BENCHMARK_ENABLE_TESTING OFF)
set(CMAKE_BUILD_TYPE Release)
add_subdirectory(benchmark)

include_directories( 
	${CMAKE_SOURCE_DIR}/benchmark/include 
	${CMAKE_SOURCE_DIR}/fmt/include  
)

if (MSVC)
	set(CMAKE_CXX_FLAGS "/EHsc /O2")
	link_libraries( benchmark )
else()
	set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O2")
	# link_directories({CMAKE_BINARY_DIR}/build/benchmark/src)
	link_libraries( benchmark pthread )
endif()

file(GLOB src "*.cpp")
#set(src xxx.cpp)

add_executable(main ${src})
# add_library(libname SHARED ${src})

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})
install (TARGETS main)

