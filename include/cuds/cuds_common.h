/******************************************************************************
 * \file cuds_common.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library common includes.
 *****************************************************************************/

#ifndef _CUDS_COMMON_H
#define _CUDS_COMMON_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include "cuds/cuds_api.h"
#include "cuds/cuds_types.h"

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------

/**
 * \brief Get the minimum of two values.
 * \param[in] a First value to compare.
 * \param[in] b Second value to compare.
 * \return The minimum of `a` and `b`.
 */
#define cuds_min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * \brief Get the maximum of two values.
 * \param[in] a First value to compare.
 * \param[in] b Second value to compare.
 * \return The maximum of `a` and `b`.
 */
#define cuds_max(x, y) (((x) > (y)) ? (x) : (y))

#endif /* _CUDS_COMMON_H */
