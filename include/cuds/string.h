/******************************************************************************
 * \file string.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS dynamic string.
 *****************************************************************************/

#ifndef CUDS_STRING_H
#define CUDS_STRING_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "cuds/export.h"
#include "cuds/types.h"

//-----------------------------------------------------------------------------
// Types definitions
//-----------------------------------------------------------------------------

/**
 * \typedef cuds_string_t
 * \brief CUDS dynamic string.
 *
 * A CUDS dynamic string behaves like a C string (null-terminated), but is
 * backed by an internal header storing metadata like length.
 * Memory layout:
 * ```
 * [ header ][ buffer... ][ '\0' ]
 *           ^
 *           |
 *         cuds_string_t
 * ```
 */
typedef char *cuds_string_t;

//-----------------------------------------------------------------------------
// Functions declarations
//-----------------------------------------------------------------------------

/**
 * \brief Create a new dynamic string.
 * \param[in] init_cstr Initialization C-string (null-terminated).
 *                      If `NULL`, an empty dynamic string is created.
 * \return New dynamic string on success, or `NULL` on failure and `errno` is set.
 */
CUDS_API cuds_string_t cuds_string_new(const char *init_cstr);

/**
 * \brief Free a dynamic string.
 * \param[in,out] self Dynamic string.
 *                 If `NULL`, nothing is done.
 * \warning The pointer is not reset to `NULL` after this call.
 *          Use `cuds_string_destroy` if you need pointer invalidation.
 */
CUDS_API void cuds_string_free(cuds_string_t self);

/**
 * \brief Free a dynamic string and reset the pointer.
 * \param[in,out] p_self Pointer to a dynamic string.
 */
CUDS_API void cuds_string_destroy(cuds_string_t *p_self);

/**
 * \brief Get the length of a dynamic string.
 * \param[in,out] self Dynamic string.
 * \return Length of the dynamic string on success, or `0` if `self` is `NULL`.
 */
CUDS_API size_t cuds_string_len(cuds_string_t self);

#endif /* CUDS_STRING_H */
