/******************************************************************************
 * \file platform.c
 * \package cuds
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Implementations for platform and compiler detection of CUDS library.
 *****************************************************************************/

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include "cuds/platform.h"

/*****************************************************************************/
/* FUNCTIONS */
/*****************************************************************************/

const char *cuds_platform(void)
{
    return CUDS_PLATFORM_NAME;
}

const char *cuds_compiler(void)
{
#if defined(CUDS_ENV_MINGW)
    return CUDS_COMPILER_NAME " (MinGW)";
#else
    return CUDS_COMPILER_NAME;
#endif
}
