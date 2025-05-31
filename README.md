# cuds - C Utilities and Data Structures

cuds is a C library providing Utilities and Data Structures implementations.

This repository includes a statically and dynamically linkable library, and full support for `pkg-config`. 

It uses simple Makefile, so no build systems like CMake or Autotools are supported.

---

## Table of Contents

- [Setup](#setup)
- [Installation](#installation)
- [Compilation](#compilation)
- [Usage](#usage)
- [Platform Compatibility](#platform-compatibility)
- [Authors](#authors)
- [License](#license)

---

## Setup

Clone the repository :

---

## Installation

To install the `cuds` library system-wide :

```sh
sudo make install
```

This will:
- Install headers into: `/usr/local/include/cuds/`
- Install static and shared libs into: `/usr/local/lib/`
- Install a pkg-config file into: `/usr/local/lib/pkgconfig/cuds.pc`

You can override the install prefix (default is `/usr/local/`) with :

```sh
sudo make DESTPREFIX=<your/install/path/> install
```

To uninstall:

```sh
sudo make uninstall
```

---

## Compilation

Build both static and shared libraries :

```sh
make
```

Build only the static library :

```sh
make libstatic
```

Build only the shared library :

```sh
make libshared
```

Clean build artifacts:

```sh
make clean      # Remove build/ and lib/ directories
make cleanall   # Remove also version and pkg-config files
```

You can choose a build type :

```sh
make BUILD_TYPE=debug     # optimizations disabled (with -g, -fsanitize=address)
make BUILD_TYPE=release   # optimizations enabled (-02)
```
The default value of `BUILD_TYPE` is `release`.

---

## Usage

After installation, projects can easily use `cuds` library by integrating `pkg-config`:

### Example usage in your own Makefile :

```makefile
CFLAGS  += $(shell pkg-config --cflags cuds)
LDFLAGS += $(shell pkg-config --libs cuds)
```

Or when compiling manually by adding `$(pkg-config --cflags --libs cuds)` to your compilation command :

### Example usage in command line :

```sh
gcc -o myprog myprog.c $(pkg-config --cflags --libs cuds)
```

---

## Platform Compatibility

This Makefile is designed for Unix-like systems and is not supported on Windows.

Officially supported systems include :
- ✅ GNU/Linux (Debian, Ubuntu, Arch, Fedora, etc.)
- ✅ Other Unix-like environments (FreeBSD, OpenBSD) with GNU toolchain
- ⚠️ macOS: partially supported — requires adaptation for `.dylib`, no `ldconfig`
- ❌ Windows: not supported (unless using WSL or MSYS2, but not officially supported)

The build system assumes :
- POSIX-compatible shell and tools (`gcc`, `ar`, `mkdir`, `rm`, etc.)
- Standard Unix-style installation paths (`/usr/local/include`, `/usr/local/lib`)
- A working `pkg-config` setup

---

## Authors

- Raphael CAUSSE

Contributions are welcome via pull requests.

---

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

---
