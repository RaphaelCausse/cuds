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
```sh
cmake --list-presets
```

Configure the project, using a preset (recommended) :
```sh
cmake --preset linux-gcc-release
```

If you prefer to configure manually, in `<BUILD_DIR>` :
```sh
cmake -S . -B <BUILD_DIR> \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=/usr/local \
    -DCUDS_BUILD_SHARED=ON \
    -DCUDS_BUILD_STATIC=OFF \
    -DCUDS_BUILD_TESTS=OFF
```

**Notes:**

- Both static and shared libraries are built by default. Enable/Disable by setting options `CUDS_BUILD_SHARED` and `CUDS_BUILD_STATIC` at configuration.
- Tests are built by default. Enable/Disable by setting option `CUDS_BUILD_TESTS` at configuration.

---


## Build

List all available build presets:
```sh
cmake --build --list-presets
```

Build the project, using a preset (recommended) :
```sh
cmake --build --preset linux-gcc-release
```

If you prefer to build manually, in `<BUILD_DIR>` :
```sh
cmake --build <BUILD_DIR>
```

---


## Install

Install the library and headers :
```sh
cmake --install <BUILD_DIR>
```

You can specify an installation prefix explicitly :
```sh
cmake --install <BUILD_DIR> --prefix <PREFIX_PATH>
```

Files are installed as follows :
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

### Using pkg-config

```sh
pkg-config --cflags --libs cuds
```

### Include headers

```c
#include <cuds/cuds.h>
```

Example projects demonstrating how to use CUDS are available in the [sample/](sample/) directory.

---


## Tests

List all available test presets :
```sh
ctest --list-presets
```

Build and run all tests, using a preset :
```sh
ctest --preset linux-gcc-debug
```

Build and run a specific test executable :
```sh
ctest --preset linux-gcc-debug -R test_version
```

---


## Clean

Remove build artifacts :
```sh
rm -rf build
```

Or clean a specific build directory :
```sh
cmake --build build/linux-gcc-release --target clean
```

---


## Authors

Raphael CAUSSE (raphael.causse2@gmail.com)
