cmake_minimum_required(VERSION 3.11)

project(main)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)

if (MSVC)
	target_compile_options(main PRIVATE /MT)
	target_compile_definitions(main PRIVATE _CRT_SECURE_NO_WARNINGS)
else()
	target_compile_options(main PRIVATE -Wall -O2)
endif()


find_package(benchmark CONFIG REQUIRED)
target_link_libraries(main PRIVATE benchmark::benchmark benchmark::benchmark_main)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE fmt::fmt)

# cmake .. -DCMAKE_TOOLCHAIN_FILE=D:/Lib/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows-static
# cmake -G "MSYS Makefiles" .. -DCMAKE_TOOLCHAIN_FILE=D:/Lib/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-mingw-static