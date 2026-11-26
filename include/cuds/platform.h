/******************************************************************************
 * \file platform.h
 * \package cuds
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Declarations for platform detection of CUDS library.
 *****************************************************************************/

#ifndef CUDS_PLATFORM_H
#define CUDS_PLATFORM_H

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include "cuds/export.h"

/*****************************************************************************/
/* PLATFORM */
/*****************************************************************************/

/**
 * Primary platform.
 */
#if defined(__linux__) || defined(__linux)
/**
 * \brief Defined only when compiling for Linux.
 */
#define CUDS_PLATFORM_LINUX 1
#define CUDS_PLATFORM_NAME "linux"

#elif defined(__APPLE__) && defined(__MACH__)
#include <TargetConditionals.h>
/**
 * \brief Defined only when compiling for Apple platforms.
 */
#define CUDS_PLATFORM_APPLE 1
#define CUDS_PLATFORM_NAME "apple"

#elif defined(__CYGWIN__)
/**
 * \brief Defined only when compiling under Cygwin (POSIX layer on Windows).
 */
#define CUDS_PLATFORM_CYGWIN 1
#define CUDS_PLATFORM_NAME "cygwin"

#elif defined(_WIN32) || defined(_WIN64)
/**
 * \brief Defined only when compiling for Windows.
 */
#define CUDS_PLATFORM_WINDOWS 1
#define CUDS_PLATFORM_NAME "windows"

#elif defined(__FreeBSD__)
/**
 * \brief Defined only when compiling for FreeBSD.
 */
#define CUDS_PLATFORM_FREEBSD 1
#define CUDS_PLATFORM_BSD 1
#define CUDS_PLATFORM_NAME "freebsd"
#elif defined(__OpenBSD__)
/**
 * \brief Defined only when compiling for OpenBSD.
 */
#define CUDS_PLATFORM_OPENBSD 1
#define CUDS_PLATFORM_BSD 1
#define CUDS_PLATFORM_NAME "openbsd"
#elif defined(__NetBSD__)
/**
 * \brief Defined only when compiling for NetBSD.
 */
#define CUDS_PLATFORM_NETBSD 1
#define CUDS_PLATFORM_BSD 1
#define CUDS_PLATFORM_NAME "netbsd"
#elif defined(__DragonFly__)
/**
 * \brief Defined only when compiling for DragonFlyBSD.
 */
#define CUDS_PLATFORM_DRAGONFLY 1
#define CUDS_PLATFORM_BSD 1
#define CUDS_PLATFORM_NAME "dragonfly"

#elif defined(__unix__) || defined(__unix)
/**
 * \brief Defined only for a generic, unrecognized Unix.
 */
#define CUDS_PLATFORM_UNIX 1
#define CUDS_PLATFORM_NAME "unix"

#else
/**
 * \brief Defined only when the platform is not recognized.
 */
#define CUDS_PLATFORM_UNKNOWN 1
#define CUDS_PLATFORM_NAME "unknown"
#endif


/**
 * Family: POSIX.
 */
#if defined(CUDS_PLATFORM_LINUX) || defined(CUDS_PLATFORM_APPLE) || \
    defined(CUDS_PLATFORM_BSD)   || defined(CUDS_PLATFORM_UNIX)  || \
    defined(CUDS_PLATFORM_CYGWIN)
/**
 * \brief Defined for every POSIX system.
 */
#define CUDS_PLATFORM_POSIX 1
#define CUDS_PLATFORM_FAMILY "posix"
#endif

/**
 * Family: Win32.
 */
#if defined(CUDS_PLATFORM_WINDOWS)
/**
 * \brief Defined for every Win32 system.
 */
#define CUDS_PLATFORM_WIN32 1
#define CUDS_PLATFORM_FAMILY "win32"
#endif


/**
 * Environment: MinGW (a Windows toolchain, not a platform).
 */
#if defined(__MINGW32__) || defined(__MINGW64__)
/**
 * \brief Defined when using a MinGW toolchain (CUDS_PLATFORM_WINDOWS is also defined).
 */
#define CUDS_MINGW 1
#endif


/**
 * Path separator.
 */
#if defined(CUDS_PLATFORM_WINDOWS)
/**
 * \brief Native path separator, as character.
 */
#define CUDS_PATH_SEP '\\'
/**
 * \brief Native path separator, as string literal.
 */
#define CUDS_PATH_SEP_STR "\\"
#else
#define CUDS_PATH_SEP '/'
#define CUDS_PATH_SEP_STR "/"
#endif

/*****************************************************************************/
/* COMPILER */
/*****************************************************************************/

#if defined(__GNUC__)
/**
 * \brief Defined when compiling with gcc.
 */
#define CUDS_COMPILER_GCC 1
#define CUDS_COMPILER_NAME "gcc"
#define CUDS_COMPILER_VERSION \
    (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#elif defined(__clang__)
/**
 * \brief Defined when compiling with clang.
 */
#define CUDS_COMPILER_CLANG 1
#define CUDS_COMPILER_NAME "clang"
#define CUDS_COMPILER_VERSION \
    (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)

#elif defined(_MSC_VER)
/**
 * \brief Defined when compiling with msvc.
 */
#define CUDS_COMPILER_MSVC 1
#define CUDS_COMPILER_NAME "msvc"
#define CUDS_COMPILER_VERSION _MSC_VER

#else
/**
 * \brief Defined when the compiler is not recognized.
 */
#define CUDS_COMPILER_UNKNOWN 1
#define CUDS_COMPILER_NAME "unknown"
#define CUDS_COMPILER_VERSION 0
#endif

#if defined(CUDS_COMPILER_GCC) || defined(CUDS_COMPILER_CLANG)
/**
 * \brief Defined for GCC-compatible compilers (GCC, Clang).
 */
#define CUDS_COMPILER_GNUC_LIKE 1
#endif

/*****************************************************************************/
/* ARCHITECTURE */
/*****************************************************************************/

/**
 * Platform architecture.
 */
#if defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
/**
 * \brief Defined for x86_64 architecture.
 */
#define CUDS_ARCH_X64 1
#define CUDS_ARCH_NAME "x86_64"
#define CUDS_ARCH_BITS 64

#elif defined(__i386__) || defined(__i386) || defined(_M_IX86)
/**
 * \brief Defined for x86 architecture.
 */
#define CUDS_ARCH_X86 1
#define CUDS_ARCH_NAME "x86"
#define CUDS_ARCH_BITS 32

#elif defined(__aarch64__) || defined(_M_ARM64)
/**
 * \brief Defined for arm64 architecture.
 */
#define CUDS_ARCH_ARM64 1
#define CUDS_ARCH_NAME "arm64"
#define CUDS_ARCH_BITS 64

#elif defined(__arm__) || defined(_M_ARM)
/**
 * \brief Defined for arm architecture
 */
#define CUDS_ARCH_ARM 1
#define CUDS_ARCH_NAME "arm"
#define CUDS_ARCH_BITS 32

#else
/**
 * \brief Defined only for unknown/unsupported architecture.
 */
#define CUDS_ARCH_UNKNOWN 1
#define CUDS_ARCH_NAME "unknown"
#if defined(__SIZEOF_POINTER__)
#define CUDS_ARCH_BITS (__SIZEOF_POINTER__ * 8)
#else
#define CUDS_ARCH_BITS 0
#endif
#endif

/*****************************************************************************/
/* BYTE ORDER */
/*****************************************************************************/

#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && defined(__ORDER_BIG_ENDIAN__)
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define CUDS_LITTLE_ENDIAN 1
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define CUDS_BIG_ENDIAN 1
#endif

#elif defined(CUDS_PLATFORM_WINDOWS) || defined(CUDS_ARCH_X86) || defined(CUDS_ARCH_X64)
#define CUDS_LITTLE_ENDIAN 1
#endif

/*****************************************************************************/
/* PORTABLE ATTRIBUTES */
/*****************************************************************************/

/** 
 * Portable `static inline` for header-only helpers.
 */
#if defined(CUDS_COMPILER_GNUC_LIKE)
#define CUDS_INLINE inline
#define CUDS_FORCE_INLINE inline __attribute__((always_inline))
#define CUDS_NOINLINE __attribute__((noinline))

#elif defined(CUDS_COMPILER_MSVC)
#define CUDS_INLINE __inline
#define CUDS_FORCE_INLINE __forceinline
#define CUDS_NOINLINE __declspec(noinline)

#else
#define CUDS_INLINE inline
#define CUDS_FORCE_INLINE inline
#define CUDS_NOINLINE
#endif


/** 
 * Portable attributes helpers.
 */
#if defined(CUDS_COMPILER_GNUC_LIKE)
/**
 * \brief Silences "unused" warnings on a variable or function.
 */
#define CUDS_UNUSED __attribute__((unused))
/**
 * \brief Marks a declaration as deprecated, with a message.
 */
#define CUDS_DEPRECATED(msg) __attribute__((deprecated(msg)))

#elif defined(CUDS_COMPILER_MSVC)
#define CUDS_UNUSED
#define CUDS_DEPRECATED(msg) __declspec(deprecated(msg))

#else
#define CUDS_UNUSED
#define CUDS_DEPRECATED(msg)
#endif

/*****************************************************************************/
/* FUNCTIONS */
/*****************************************************************************/

CUDS_EXTERN_C_BEGIN

/**
 * \brief Get the name of the platform the library was built for.
 * \return Value of CUDS_PLATFORM_NAME, never NULL.
 * \note With the shared library, this is the platform of the library, which
 * is the one the program runs on.
 */
CUDS_API const char *cuds_platform(void);

/**
 * \brief Get the name of the platform family the library was built for.
 * \return Value of CUDS_PLATFORM_FAMILY, never NULL.
 * \note With the shared library, this is the platform family of the library,
 * which * is the one the program runs on.
 */
CUDS_API const char *cuds_platform_family(void);

/** 
 * \brief Get the name of the compiler used to build the library.
 * \return Value of CUDS_COMPILER_NAME, never NULL.
 */
CUDS_API const char *cuds_compiler(void);

/**
 * \brief Get the name of the CPU architecture the library was built for.
 * \return Value of CUDS_ARCH_NAME.
 */
CUDS_API const char *cuds_arch(void);

CUDS_EXTERN_C_END

#endif /* CUDS_PLATFORM_H */
