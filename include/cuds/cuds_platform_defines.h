/******************************************************************************
 * \file cuds_platform_defines.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library platform detection.
 *****************************************************************************/

#ifndef CUDS_PLATFORM_DEFINES_H
#define CUDS_PLATFORM_DEFINES_H

/*****************************************************************************/
/* MACROS */
/*****************************************************************************/

#if (defined(_WIN32) || defined(_WIN64))
/**
 * \brief Macro defined only if compiling for Windows.
 */
#define CUDS_PLATFORM_WINDOWS
#endif /* WINDOWS */

#if (defined(__linux__) || defined(__linux) || defined(linux))
/**
 * \brief Macro defined only if compiling for Linux.
 */
#define CUDS_PLATFORM_LINUX
#endif /* LINUX */

#if defined(__APPLE__)
/**
 * \brief Macro defined only if compiling for Apple.
 */
#define CUDS_PLATFORM_APPLE
#endif /* APPLE */

#if (defined(__unix__) || defined(__unix) || defined(unix))
/**
 * \brief Macro defined only if compiling for Unix-like systems.
 * \note Other platforms, like Linux, might define this in addition to their define.
 */
#define CUDS_PLATFORM_UNIX
#include <unistd.h>
#endif /* UNIX */

#if defined(_POSIX_VERSION)
/**
 * \brief Macro defined only if compiling for POSIX systems.
 */
#define CUDS_POSIX
#endif /* POSIX */

#endif /* CUDS_PLATFORM_DEFINES_H */
