/******************************************************************************
 * \file algorithms.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library algorithm helpers.
 *****************************************************************************/

#ifndef CUDS_ALGORITHM_H
#define CUDS_ALGORITHM_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "cuds/types.h"

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

/**
 * \brief Get the minimum of two values.
 * \param[in] a First value to compare.
 * \param[in] b Second value to compare.
 * \return The minimum of `a` and `b`.
 */
static inline size_t cuds_min(size_t a, size_t b)
{
    return (a < b) ? a : b;
}

/**
 * \brief Get the maximum of two values.
 * \param[in] a First value to compare.
 * \param[in] b Second value to compare.
 * \return The maximum of `a` and `b`.
 */
static inline size_t cuds_max(size_t a, size_t b)
{
    return (a > b) ? a : b;
}

#endif /* CUDS_ALGORITHM_H */