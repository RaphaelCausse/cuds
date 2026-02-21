/******************************************************************************
 * \file platform.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library platform and compiler detection .
 *****************************************************************************/

#ifndef CUDS_PLATFORM_H
#define CUDS_PLATFORM_H

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------

/* Platform detection */

#if defined(_WIN32) || defined(_WIN64)
  #define CUDS_PLATFORM_WINDOWS (1)
#else
  #define CUDS_PLATFORM_WINDOWS (0)
#endif /* _WIN32 */

#if defined(__linux__)
  #define CUDS_PLATFORM_LINUX (1)
#else
  #define CUDS_PLATFORM_LINUX (0)
#endif /* __linux__ */

#if defined(__APPLE__) && defined(__MACH__)
  #define CUDS_PLATFORM_MACOS 1
#else
  #define CUDS_PLATFORM_MACOS (0)
#endif /* __APPLE__ */

#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
  #define CUDS_PLATFORM_UNIX (1)
#else
  #define CUDS_PLATFORM_UNIX (0)
#endif /* __unix__ */

/* POSIX detection */

#if CUDS_PLATFORM_UNIX
  #include <unistd.h>
#endif /* CUDS_PLATFORM_UNIX */
#if defined(_POSIX_VERSION)
  #define CUDS_POSIX (1)
#else
  #define CUDS_POSIX (0)
#endif /* _POSIX_VERSION */

/* Compiler detection */

#if defined(_MSC_VER)
  #define CUDS_COMPILER_MSVC (1)
#else
  #define CUDS_COMPILER_MSVC (0)
#endif /* _MSC_VER */

#if defined(__clang__)
  #define CUDS_COMPILER_CLANG (1)
#else
  #define CUDS_COMPILER_CLANG (0)
#endif /* __clang__ */

#if defined(__GNUC__) && !defined(__clang__)
  #define CUDS_COMPILER_GCC (1)
#else
  #define CUDS_COMPILER_GCC (0)
#endif /* __GNUC__ */

#endif /* CUDS_PLATFORM_H */
