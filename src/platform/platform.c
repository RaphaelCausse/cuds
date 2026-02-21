/******************************************************************************
 * \file platform.c
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Implementation for CUDS library platform.
 *****************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "cuds/cuds_platform.h"

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

const char *cuds_platform(void)
{
#if defined(CUDS_PLATFORM_WINDOWS)
    return "Windows";
#elif defined(CUDS_PLATFORM_LINUX)
    return "Linux";
#elif defined(CUDS_PLATFORM_APPLE)
    return "Apple";
#else
    return "Unknown";
#endif
}
