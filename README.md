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

You can configure the installation path at setup (see Notes in [Install](#install)).

---


## Build

Compile the project :
```shell
meson compile -C <build_dir>

# With verbose output
meson compile -C <build_dir> --verbose
```

**Notes** :
- By default, this builds both the static and the shared library (depending on `default_library` option).

---


## Install

Installation is handled by Meson with pkg-config.

Install the library and public headers using default installation path (see **Notes**) :
```shell
meson install -C <build_dir>
```

You can configure the installation path at setup with the `prefix` option (see **Notes**).
```shell
meson setup <build_dir> --prefix=<path/to/install>

# If project already setup, you might need to reconfigure it
meson setup <build_dir> --prefix=<path/to/install> --reconfigure

# Then compile, and install
meson compile -C <build_dir>
meson install -C <build_dir>
```

You can override the installation path with `destdir` option (will override the `prefix` option) :
```shell
meson install -C <build_dir> --destdir=<path/to/install>
```

**Notes** :
- Installation prefix path set with option `prefix` defaults to `C:\` on Windows and `/usr/local` otherwise.
- If you are using MSYS2 on Windows, define the `prefix` or `destdir` option to the path of your MSYS2 environment, for pkg-config compatibility :
    ```shell
     # Configure installation path for MSYS2 at setup  
     meson setup <build_dir> --prefix=C:/msys64/ucrt64

     # Configure installation path for MSYS2 at install 
     meson install -C <build_dir> --destdir=C:/msys64/ucrt64
    ```

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
