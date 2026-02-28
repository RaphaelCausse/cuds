/******************************************************************************
 * \file cuds_api.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library API symbol visibility and ABI control.
 *****************************************************************************/

#ifndef _CUDS_API_H
#define _CUDS_API_H

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include "cuds/cuds_platform_defines.h"

/*****************************************************************************/
/* MACROS */
/*****************************************************************************/

#if defined(CUDS_PLATFORM_WINDOWS)
#if defined(CUDS_SHARED) && defined(CUDS_SHARED_EXPORT)
/* Building the shared library, exports symbols */
#define CUDS_API __declspec(dllexport)
#elif defined(CUDS_SHARED) && !defined(CUDS_SHARED_EXPORT)
/* Using the shared library, imports symbols */
#define CUDS_API __declspec(dllimport)
#else /* CUDS_SHARED */
#define CUDS_API
#endif /* CUDS_SHARED */
#else  /* CUDS_PLATFORM_WINDOWS */
#if defined(CUDS_SHARED)
#define CUDS_API __attribute__((visibility("default")))
#else /* CUDS_SHARED */
#define CUDS_API
#endif /* CUDS_SHARED */
#endif /* CUDS_PLATFORM_WINDOWS */

#endif /* _CUDS_API_H */
