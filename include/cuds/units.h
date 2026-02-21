/******************************************************************************
 * \file units.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library units handleling.
 *****************************************************************************/

#ifndef CUDS_UNITS_H
#define CUDS_UNITS_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <stddef.h>
#include <stdint.h>

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------

/**
 * \brief Convert a value expressed in kilobytes to bytes.
 * \param[in] n Number of kilobytes.
 * \return The equivalent size in bytes.
 * \note Uses binary units (1 KB = 1024 bytes).
 */
#define CUDS_KB(n) ((size_t)(n) << 10)

/**
 * \brief Convert a value expressed in megabytes to bytes.
 * \param[in] n Number of megabytes.
 * \return The equivalent size in bytes.
 * \note Uses binary units (1 MB = 1024^2 bytes).
 */
#define CUDS_MB(n) ((size_t)(n) << 20)

/**
 * \brief Convert a value expressed in gigabytes to bytes.
 * \param[in] n Number of gigabytes.
 * \return The equivalent size in bytes.
 * \note Uses binary units (1 GB = 1024^3 bytes).
 */
#define CUDS_GB(n) ((size_t)(n) << 30)

#endif /* CUDS_UNITS_H */