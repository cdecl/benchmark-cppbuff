
# benchmark-cppbuff


## Git clone

```sh
$ git clone https://github.com/cdecl/benchmark-cppbuff.git
$ cd benchmark-cppbuff
```

### Package install 

#### Linux

```sh
$  ./vcpkg install benchmark fmt
Computing installation plan...
The following packages are already installed:
    benchmark[core]:x64-linux -> 1.5.5
    fmt[core]:x64-linux -> 7.1.3#5
Package benchmark:x64-linux is already installed
Package fmt:x64-linux is already installed

Total elapsed time: 6.6 us

The package benchmark:x64-linux provides CMake targets:

    find_package(benchmark CONFIG REQUIRED)
    target_link_libraries(main PRIVATE benchmark::benchmark benchmark::benchmark_main)

The package fmt provides CMake targets:

    find_package(fmt CONFIG REQUIRED)
    target_link_libraries(main PRIVATE fmt::fmt)

    # Or use the header-only version
    find_package(fmt CONFIG REQUIRED)
    target_link_libraries(main PRIVATE fmt::fmt-header-only)
```

#### Windows 

```sh
$ vcpkg install benchmark fmt --triplet=x64-windows-static
Computing installation plan...
The following packages are already installed:
    benchmark[core]:x64-windows-static -> 1.5.5
    fmt[core]:x64-windows-static -> 7.1.3#5
Package benchmark:x64-windows-static is already installed
Package fmt:x64-windows-static is already installed

Total elapsed time: 483.1 us

The package benchmark:x64-windows-static provides CMake targets:

    find_package(benchmark CONFIG REQUIRED)
    target_link_libraries(main PRIVATE benchmark::benchmark benchmark::benchmark_main)

The package fmt provides CMake targets:

    find_package(fmt CONFIG REQUIRED)
    target_link_libraries(main PRIVATE fmt::fmt)

    # Or use the header-only version
    find_package(fmt CONFIG REQUIRED)
    target_link_libraries(main PRIVATE fmt::fmt-header-only)
```

---

### Build 

#### Linux

```sh
# benchmark -DCMAKE_BUILD_TYPE=Release
$ cmake -B build -DCMAKE_TOOLCHAIN_FILE=<vcpkg>/scripts/buildsystems/vcpkg.cmake  -DCMAKE_BUILD_TYPE=Release .

# build
$ cmake --build build

# Run
$ build/main
```

### Windows 

```sh
#
$ cmake -B build-vc -A x64 -DCMAKE_TOOLCHAIN_FILE=D:/Lib/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows-static .

# build
$ cmake --build build-vc --config Release

## Run
$ build-vc\Release\main
```
