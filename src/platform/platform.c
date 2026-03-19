/******************************************************************************
 * \file platform.c
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Implementation for CUDS library platform detection.
 *****************************************************************************/

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include "cuds/cuds_platform.h"

/*****************************************************************************/
/* FUNCTIONS */
/*****************************************************************************/

const char *cuds_platform(void)
{
#if defined(CUDS_PLATFORM_WINDOWS)
    return "Windows";
#elif defined(CUDS_PLATFORM_LINUX)
    return "Linux";
#elif defined(CUDS_PLATFORM_APPLE)
    return "Apple";
#elif defined(CUDS_PLATFORM_UNIX)
    return "Unix";
#else
    return "Unknown";
#endif
}
