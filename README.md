# benchmark-cppbuff


### Git Submodule Init 

```
git clone https://github.com/cdecl/benchmark-cppbuff.git
cd benchmark-cppbuff

git submodule init
git submodule update
```

### Build - Posix

```sh
$ mkdir build 
$ cd build

$ cmake ..
$ make 

## Run
$ main
```

### Build - MinGW

```sh
$ mkdir build 
$ cd build

$ SET CMAKE_CXX_COMPILER=g++ 
$ cmake -G "MinGW Makefiles" ..
$ make 

## Run
$ main
```

### Build - MSVC

```sh
## MSVC Command Prompt
$ mkdir build 
$ cd build

$ cmake ..

$ msbuild main.sln -p:Configuration=Release

## Run
$ Release\main
```