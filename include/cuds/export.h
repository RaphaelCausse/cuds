/******************************************************************************
 * \file export.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library symbol visibility and export.
 *****************************************************************************/

#ifndef CUDS_EXPORT_H
#define CUDS_EXPORT_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "cuds/platform.h"

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------

/* Symbols visibility */

#if CUDS_PLATFORM_WINDOWS
  #if defined(CUDS_SHARED) && defined(CUDS_SHARED_EXPORT)
    /* Building the shared library, exports symbols */
    #define CUDS_API __declspec(dllexport)
  #elif defined(CUDS_SHARED) && !defined(CUDS_SHARED_EXPORT)
    /* Using the shared library, imports symbols */
    #define CUDS_API __declspec(dllimport)
  #else
    #define CUDS_API
  #endif

#elif (CUDS_PLATFORM_UNIX || CUDS_PLATFORM_LINUX || CUDS_PLATFORM_MACOS)
  #if (CUDS_COMPILER_GCC || CUDS_COMPILER_CLANG)
    #define CUDS_API __attribute__((visibility("default")))
  #else
    #define CUDS_API
  #endif

#else
  #define CUDS_API
#endif /* CUDS_PLATFORM_WINDOWS */

#endif /* CUDS_EXPORT_H */
