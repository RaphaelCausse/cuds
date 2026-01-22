# CUDS - C Utilities and Data Structures

CUDS is a C library providing generic data structures, common utilities, and helper modules.

It uses Meson as its build system.

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
│ ├── meson.build
│ └── cuds/
│ ├── *.h
│ └── ...
│
├── src/            # CUDS module sources
│ ├── meson.build
│ ├── module1/
│ │ ├── *.c
│ │ └── *.h
│ └── ...
│
├── meson.build     # Top-level Meson file
└── README.md
```

---


## Requirements

- C99-compatible compiler (GCC, Clang, or MSVC)
- Python (>= 3.8)
- Meson (>= 0.60.0)
- Ninja

### Installation of Meson and Ninja (via Python)

Meson and Ninja can be installed using Python and pip, which is the recommended and most portable method.
```shell
python --version
pip --version

pip install meson ninja

meson --version
ninja --version
```

---


## Modules

Modules are defined as subdirectories in `src/`.

Each module:
- provides one or more .c source files
- may define internal headers
- exposes public headers via `include/cuds/`

---


## Configuration

Configure the build, at the root of the project :
```shell
meson setup <build_dir>
```

You can configure multiple build directories, depending on the build type :
```shell
# Defaut build type is release
meson setup <build_dir>

# Build in debug, in a separate build directory
meson setup <build_debug_dir> --buildtype=debug
# or
meson setup <build_debug_dir> --buildtype=debugoptimized
```

---


## Build

Compile the project, by specifying the build directory :
```shell
meson compile -C <build_dir>
```

By default, this builds both the static and the shared library (depending on `default_library` option in `meson.build`).

---


## Install

Install the library and public headers using default installation prefix path (see **Notes** below):
```shell
meson install -C <build_dir>
```

You can customize the installation path :
```shell
# Using destination directory
meson install -C <build_dir> --destdir=<path/to/install>

# or with environment variable
DESTDIR=<path/to/install> meson install -C <build_dir>

# or with installation prefix path at setup
meson setup <build_dir> --prefix=<path/to/install>
meson compile -C <build_dir>
meson install -C <build_dir>
```

This installs :
* Libraries :
    - `<destdir|prefix>/lib/libcuds.a` (static)
    - `<destdir|prefix>/lib/libcuds.so` (shared)
* Public headers :
    - `<destdir|prefix>/include/cuds/*.h`

**Notes** :
- Installation prefix path set with option `prefix` defaults to `C:\` on Windows and `/usr/local` otherwise.

---


## Usage

### Sample projects using Meson

Example projects demonstrating how to use CUDS are available in the [sample/](sample/) directory.

These samples show how to :
- Configure projects using Meson
- Include CUDS public headers
- Link against the CUDS static or shared library

---


## Tests

Build and run a single test :
```shell
meson test -C <build_dir> <test_name>
```

Build and run all tests :
```shell
meson test -C <build_dir>
```

**Notes** :
- All tests are compiled with the current build type.
- The stdout of passing tests is normally hidden; to see it, use `--verbose` or run the executable directly

---


## Clean

Remove build artifacts :
```shell
meson compile -C <build_dir> --clean
```

To completely reset the build directory, delete it and then reconfigure the build (see [build](#build)) :
```shell
rm -rf <build_dir>

meson setup <build_dir>
```

---


## Authors

Raphael CAUSSE (raphael.causse2@gmail.com)
