# CUDS Intro

A small sample project demonstrating how to use the CUDS library and build it with Meson.

---


## Table of Contents

1. [Project Structure](#project-structure)  
2. [Requirements](#requirements)
3. [Configuration](#modules)
4. [Build](#build)  
5. [Run](#install)
6. [Clean](#clean)

---


## Project Structure

```
cuds-intro/
├── src/
│   ├── hello.c   
│   ├── hello.h   
│   └── main.c
├── meson.build
└── README.md
```

---


## Requirements

- C99-compatible compiler (GCC, Clang, or MSVC)
- Python (>= 3.8)
- Meson (>= 0.60.0)
- Ninja

---


## Configuration

Configure the build, and optionaly specify the installation path of CUDS library :
```shell
# For default installation in /usr/local
meson setup <build_dir>

# For custom CUDS installation path
meson setup <build_dir> -Dcuds_install_path=<path/to/cuds/install>
```

You can configure multiple build directories, depending on the build type :
```shell
meson setup <build_debug_dir> --buildtype=debug
# or
meson setup <build_debug_dir> --buildtype=debugoptimized
```

**Notes** :
- If you are using MSYS2 on Windows, please define the `prefix` option to the path of your MSYS2 environment :
```shell
meson setup <build_dir> --prefix=C:/msys64/ucrt64
```
- It allow standard behavior for searching installed libraries on MSYS2.

---


## Build

Compile the project :
```shell
meson compile -C <build_dir>

# With verbose output
meson compile -C <build_dir> --verbose
```

---


## Run

Setup devenv provided by Meson for the build, then run the executable:
```shell
# Setup meson devenv into the build directory
meson devenv -C <build_dir>

# Run the executable
./cuds-intro

# Then exit the devenv
exit
```

Or simply run the executable from the build directory :
```shell
./build/cuds-intro
```

---


## Clean

Clean the project :
```shell
meson compile -C <build_dir> --clean
```
