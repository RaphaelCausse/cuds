/******************************************************************************
 * \file cuds_platform_defines.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library platform detection.
 *****************************************************************************/

#ifndef _CUDS_PLATFORM_DEFINES_H
#define _CUDS_PLATFORM_DEFINES_H

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------

/* Windows */
#if (defined(_WIN32) || defined(_WIN64))
  /**
   * \brief Macro defined only if compiling for Windows.
   */
  #define CUDS_PLATFORM_WINDOWS
#endif /* _WIN32 */

/* Linux */
#if (defined(__linux__) || defined(__linux) || defined(linux))
  /**
   * \brief Macro defined only if compiling for Linux.
   */
  #define CUDS_PLATFORM_LINUX
#endif /* __linux__ */

/* Apple */
#if defined(__APPLE__)
  /**
   * \brief Macro defined only if compiling for Apple.
   */
  #define CUDS_PLATFORM_APPLE
#endif /* __APPLE__ */

/* Unix-like */
#if (defined(__unix__) || defined(__unix) || defined(unix))
  /**
   * \brief Macro defined only if compiling for Unix-like systems.
   * \note Other platforms, like Linux, might define this in addition to their define.
   */
  #define CUDS_PLATFORM_UNIX
#endif /* __unix__ */

/* POSIX */
#if CUDS_PLATFORM_UNIX
  #include <unistd.h>
#endif /* CUDS_PLATFORM_UNIX */
#if defined(_POSIX_VERSION)
  /**
   * \brief Macro defined only if compiling for POSIX systems.
   */
  #define CUDS_POSIX
#endif /* _POSIX_VERSION */

#endif /* _CUDS_PLATFORM_DEFINES_H */
