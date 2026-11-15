/******************************************************************************
 * \file version.h
 * \package cuds
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Implementations for compile-time and runtime version of CUDS library.
 *****************************************************************************/

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include <stdint.h>
#include <stdbool.h>

#include "cuds/version.h"

/*****************************************************************************/
/* DEFINES */
/*****************************************************************************/

#ifndef CUDS_REVISION
#define CUDS_REVISION "norevision"
#endif

/*****************************************************************************/
/* FUNCTIONS */
/*****************************************************************************/

uint32_t cuds_version(void)
{
    return (uint32_t)CUDS_VERSION;
}

const char *cuds_version_string(void)
{
    return CUDS_VERSION_STRING;
}

const char *cuds_revision(void)
{
    return CUDS_REVISION;
}

bool cuds_version_is_compatible(uint32_t compiled)
{
    uint32_t linked = cuds_version();

    if (CUDS_VERSIONNUM_MAJOR(compiled) != CUDS_VERSIONNUM_MAJOR(linked))
    {
        return 0;
    }
    return (bool)(linked >= compiled);
}
