# CUDS - C Utilities and Data Structures

CUDS is a C library providing generic data structures, common utilities, and helper modules.

---


## Table of Contents

1. [Project Structure](#project-structure)  
2. [Requirements](#requirements)
3. [Modules](#modules)
4. [Configuration](#configuration)
5. [Build](#build)  
6. [Install](#install)
7. [Usage](#usage)
8. [Tests](#tests)
9. [Clean](#clean)
10. [Authors](#authors)

---


## Project Structure

```
cuds/
├── include/        # Public headers
│   └── cuds/
│       ├── *.h
│       └── ...
├── src/            # CUDS module sources
│   ├── module1/
│   │   ├── *.c
│   │   └── *.h
│   └── ...
├── tests/          # Unit tests
│   ├── *.c
│   └── ...
├── CMakeLists.txt  # Top-level CMake configuration
└── README.md
```

---


## Requirements

- C99-compatible compiler (GCC, Clang, or MSVC)
- CMake >= 3.16

---


## Modules

Modules are defined as subdirectories in `src/`.

Each module:
- provides one or more .c source files
- may define internal headers
- exposes public headers via `include/cuds/`

---


## Configuration

Configure the project with CMake :
```shell
cmake -S . -B build
```

You can specify build type explicitly (default is Release) :
```shell
# Release build
cmake -S . -B build/release -DCMAKE_BUILD_TYPE=Release

# Debug build
cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=Debug

# Release build with debug info
cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=RelWithDebInfo
```

You can also set installation paths :
```shell
# Custom installation prefix
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/usr/local
```

---


## Build

Compile the project :
```shell
cmake --build build
```

**Notes:**

- Both static and shared libraries are built if enabled via `CUDS_BUILD_SHARED` and `CUDS_BUILD_STATIC`.
- To enable or disable building shared/static libraries, pass options at configure time :
    ```shell
    cmake -S . -B build -DCUDS_BUILD_SHARED=ON -DCUDS_BUILD_STATIC=OFF  
    ```

---


## Install

Install the library and headers :
```shell
cmake --install build
```

You can specify an installation prefix explicitly :
```shell
cmake --install build --prefix /usr/local
```

This will install :

- Public headers to `<prefix>/include/cuds`
- Libraries to `<prefix>/lib`
- CMake Package config files to `<prefix>/lib/cmake/cuds`
- Pkg-config files to `<prefix>/lib/pkgconfig`

**Notes:**

- The library supports pkg-config. A .pc file is installed in the correct `lib/pkgconfig/` folder.
- For MSYS2 environments, set the prefix to the MSYS2 path for compatibility with pkg-config :
    ```shell
    cmake -S . -B build -DCMAKE_INSTALL_PREFIX=C:/msys64/ucrt64
    cmake --build build
    cmake --install build
    ```

---


## Usage

To use CUDS in another CMake project :
```cmake
# Find the installed CUDS library
find_package(cuds REQUIRED)

# Link against the shared or static library explicitly
target_link_libraries(my_target PRIVATE cuds::cuds_shared)  # for shared library
# target_link_libraries(my_target PRIVATE cuds::cuds_static) # for static library
```

Include the public headers in your source files :
```c
#include <cuds/cuds.h>
#include <cuds/value.h>
```

Example projects demonstrating how to use CUDS are available in the [sample/](sample/) directory.

---


## Tests

Build and run all tests :
```shell
cmake --build build --target all
ctest --output-on-failure
```

Build and run a specific test executable :
```shell
ctest -R test_version --output-on-failure
```

**Notes:**

- Tests are built according to the current build type.
- Option `--output-on-failure` prints stdout/stderr of failing tests.

---


## Clean

Remove build artifacts :
```shell
cmake --build build --target clean

# or

rm -rf build
```

Don't forget to reconfigure after cleaning.

---


## Authors

Raphael CAUSSE (raphael.causse2@gmail.com)
