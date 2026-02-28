/******************************************************************************
 * \file cuds_types.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library standard types.
 *****************************************************************************/

#ifndef _CUDS_TYPES_H
#define _CUDS_TYPES_H

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/*****************************************************************************/
/* TYPES */
/*****************************************************************************/

/**
 * \brief Byte, 8-bit.
 */
typedef uint8_t byte_t;

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

#endif /* _CUDS_TYPES_H */