# CUDS Intro

A small sample project demonstrating how to use the CUDS library and build it with Meson.

---


## Table of Contents

1. [Project Structure](#project-structure)  
2. [Requirements](#requirements)  
3. [Build Configuration](#build-configuration)  
4. [Build](#build)  
5. [Run](#run)  
6. [Clean](#clean)

---


## Project Structure

```
cuds-intro/
├── src/
│   ├── *.c   
│   └── *.h
├── CMakeLists.txt
└── README.md
```

---


## Requirements

- C99-compatible compiler (GCC, Clang, or MSVC)
- CMake ≥ 3.16
- An installed **CUDS** library (built and installed beforehand)

---


## Configuration

Configure the build, and optionaly specify the installation path of CUDS library :
```shell
# For default installation path
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

# For custom CUDS installation path
cmake -S . -B build \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_PREFIX_PATH=<path/to/cuds/install>
```

**Notes** :
- If you are using MSYS2 on Windows, please define the prefix path to the path of your MSYS2 environment :
```shell
cmake -S . -B build \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_PREFIX_PATH=C:/msys64/ucrt64
```
- It allow standard behavior for searching installed libraries on MSYS2 with CMake.

---


## Build

Compile the project :
```shell
cmake --build build
```

To rebuild from scratch :
```shell
cmake --build build --clean-first
```
---


## Run

Run the executable :
```shell
./build/cuds-intro
```

---


## Clean

Clean the project, remove all build artifacts :
```shell
rm -rf build
```

## Notes

This project links explicitly against one of the exported CUDS targets :
- `cuds::cuds_shared` (shared library)
- `cuds::cuds_static` (static library)
