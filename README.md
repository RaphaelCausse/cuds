# CUDS - C Utilities and Data Structures

CUDS is a C library providing generic data structures, common utilities, and helper modules.

---


## Table of Contents

1. [Requirements](#requirements)
2. [Configuration](#configuration)
3. [Build](#build)  
4. [Install](#install)
5. [Usage](#usage)
6. [Tests](#tests)
7. [Clean](#clean)
8. [Authors](#authors)

---


## Requirements

- C99-compatible compiler (GCC, Clang, or MSVC)
- CMake >= 3.16
- Ninja (recommended)

---


## Configuration

List all available configure presets:
```shell
cmake --list-presets
```

Configure the project, using a preset (recommended) :
```shell
cmake --preset linux-gcc-release
```

If you prefer to configure manually :
```shell
cmake -S . -B build/release \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=/usr/local
```

---


## Build

List all available build presets:
```shell
cmake --build --list-presets
```

Build the project, using a preset (recommended) :
```shell
cmake --build --preset linux-gcc-release
```

**Notes:**

- Both static and shared libraries are built if enabled via `CUDS_BUILD_SHARED` and `CUDS_BUILD_STATIC` that you can set.

---


## Install

Install the library and headers :
```shell
cmake --install <BUILD_DIR>

# Example : cmake --install build/linux-gcc-release
```

You can specify an installation prefix explicitly :
```shell
cmake --install <BUILD_DIR> --prefix <PREFIX_PATH>
```

Files are installed as follows:
* Headers : `<PREFIX_PATH>/include/cuds`
* Libraries : `<PREFIX_PATH>/lib`
* CMake package config : `<PREFIX_PATH>/lib/cmake/cuds`
* pkg-config file : `<PREFIX_PATH>/lib/pkgconfig`

---


## Usage

### Using CMake

```cmake
# Find the installed CUDS library
find_package(cuds REQUIRED)

# Link against the shared or static library explicitly
target_link_libraries(my_target PRIVATE cuds::cuds_shared)
# or
# target_link_libraries(my_target PRIVATE cuds::cuds_static)
```

### Include headers

```c
#include <cuds/cuds.h>
#include <cuds/arena.h>
```

### Using pkg-config

```shell
pkg-config --cflags --libs cuds
```

Example projects demonstrating how to use CUDS are available in the [sample/](sample/) directory.

---


## Tests

List all available test presets :
```shell
ctest --list-presets
```

Build and run all tests, using a preset :
```shell
ctest --preset linux-gcc-debug
```

Build and run a specific test executable :
```shell
ctest --preset linux-gcc-debug -R test_version
```

---


## Clean

Remove build artifacts :
```shell
rm -rf build
```

Or clean a specific build directory :
```shell
cmake --build build/linux-gcc-release --target clean
```

---


## Authors

Raphael CAUSSE (raphael.causse2@gmail.com)
