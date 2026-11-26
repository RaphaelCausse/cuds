/******************************************************************************
 * \file platform.c
 * \package cuds
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Implementations for platform detection of CUDS library.
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

const char *cuds_platform_family(void)
{
    return CUDS_PLATFORM_FAMILY;
}

const char *cuds_compiler(void)
{
    return CUDS_COMPILER_NAME;
}

const char *cuds_arch(void)
{
    return CUDS_ARCH_NAME;
}
