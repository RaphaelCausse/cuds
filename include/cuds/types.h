/******************************************************************************
 * \file types.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library standard types.
 *****************************************************************************/

#ifndef CUDS_TYPES_H
#define CUDS_TYPES_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <stdint.h>
#include <stdbool.h>

//-----------------------------------------------------------------------------
// Types
//-----------------------------------------------------------------------------

/**
 * \brief Single precision floating point number, 32-bit.
 * Assumes IEEE-754 binary32.
 */
typedef float float32_t;

/**
 * \brief Double precision floating point number, 64-bit.
 * Assumes IEEE-754 binary64.
 */
typedef double float64_t;

#endif /* CUDS_TYPES_H */