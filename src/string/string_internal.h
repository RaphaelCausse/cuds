/******************************************************************************
 * \file string_internal.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Internal header for CUDS dynamic string.
 *****************************************************************************/

#ifndef CUDS_STRING_INTERNAL_H
#define CUDS_STRING_INTERNAL_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "cuds_internal.h"

//-----------------------------------------------------------------------------
// Types definitions
//-----------------------------------------------------------------------------

/**
 * \struct icuds_string_header_t
 * \brief Internal header preceding the string buffer.
 */
typedef struct
{
    size_t length; /**< Current string length (excluding null terminator). */
    size_t alloc;  /**< Allocated buffer size (excluding header). */
    char buffer[]; /**< Flexible array holding string characters. */
} icuds_string_header_t;

//-----------------------------------------------------------------------------
// Macros definitions
//-----------------------------------------------------------------------------

/**
 * \brief Retrieve the internal header pointer from a CUDS dynamic string.
 * \param[in] str Dynamic string.
 * \return Pointer to the associated internal header.
 */
#define ICUDS_STRING_HEADER(str) \
    ((icuds_string_header_t *)((str) - (sizeof(icuds_string_header_t))))

//-----------------------------------------------------------------------------
// Functions declarations
//-----------------------------------------------------------------------------

/**
 * \brief Initialize a new dynamic string with a given length.
 * \param[in] init_cstr Initialization C-string (null-terminated).
 *                      If `NULL`, an empty dynamic string is created.
 * \param[in] init_length Length of the initialization string.
 * \return New dynamic string on success, or `NULL` on failure and `errno` is set.
 */
cuds_string_t icuds_string_init(const char *init_cstr, size_t init_length);

#endif /* CUDS_STRING_INTERNAL_H */
