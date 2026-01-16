# CUDS Intro

A small sample project demonstrating how to use the CUDS library and build it with Meson.

---


## Table of Contents

1. [Project Structure](#project-structure)  
2. [Requirements](#requirements)
3. [Configuration](#modules)
4. [Build](#build)  
5. [Run](#install)
6. [Notes](#Notes)

---


## Project Structure

```
cuds-intro/
├── src/
│   ├── hello.c   
│   ├── hello.h   
│   └── main.c
├── meson.build         # Meson build definition
└── README.md
```

---


## Requirements

* C99-compatible compiler (GCC, Clang, MSVC with C99 support)
* Python 3.x
* Meson ≥ 0.60.0
* Ninja (or another Meson backend)

---


## Configuration

If the CUDS library is not installed in `/usr/local/cuds` by default , you must provide the installation path using the Meson option `prefix` at setup.
```shell
# For default installation path
meson setup <build_dir>

# For custom installation path
meson setup <build_dir> --prefix=<path/to/cuds/install>
```
