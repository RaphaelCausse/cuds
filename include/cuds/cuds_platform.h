/******************************************************************************
 * \file cuds_platform.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library platform dectection.
 *****************************************************************************/

#ifndef CUDS_PLATFORM_H
#define CUDS_PLATFORM_H

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include "cuds/cuds_common.h"
#include "cuds/cuds_platform_defines.h"

/*****************************************************************************/
/* FUNCTIONS */
/*****************************************************************************/

/**
 * \brief Get the name of the platform.
 * \return Return the name of the platform if supported, otherwise "Unknown".
 */
extern CUDS_API const char *cuds_platform(void);

#endif /* CUDS_PLATFORM_H */
