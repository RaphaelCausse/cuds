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

#include <stddef.h>
#include <stdint.h>

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------

/**
 * \brief True boolean value.
 */
#define CUDS_TRUE (1)

/**
 * \brief False boolean value.
 */
#define CUDS_FALSE (0)

//-----------------------------------------------------------------------------
// Types
//-----------------------------------------------------------------------------

/**
 * \brief Boolean, 8-bit.
 */
typedef uint8_t bool8_t;

/**
 * \brief Boolean, 32-bit.
 */
typedef uint32_t bool32_t;

/**
 * \brief Single precision floating point number (IEEE-754 binary32), 32-bit.
 */
typedef float float32_t;

/**
 * \brief Double precision floating point number (IEEE-754 binary64), 64-bit.
 */
typedef double float64_t;

#endif /* CUDS_TYPES_H */