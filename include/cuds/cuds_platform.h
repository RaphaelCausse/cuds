/******************************************************************************
 * \file cuds_platform.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library platform dectection.
 *****************************************************************************/

#ifndef _CUDS_PLATFORM_H
#define _CUDS_PLATFORM_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "cuds/cuds_common.h"
#include "cuds/cuds_platform_defines.h"

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

/**
 * \brief Get the name of the platform.
 * \return Return the name of the platform if supported, otherwise "Unknown".
 */
extern CUDS_API const char *cuds_platform(void);

#endif /* _CUDS_PLATFORM_H */
