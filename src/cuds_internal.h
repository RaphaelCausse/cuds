/******************************************************************************
 * \file cuds_internal.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Internal header for CUDS library.
 *****************************************************************************/

#ifndef CUDS_INTERNAL_H
#define CUDS_INTERNAL_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <stdlib.h>

//-----------------------------------------------------------------------------
// Macros definitions
//-----------------------------------------------------------------------------

/**
 * \brief Allocate memory.
 * \param[in] size Number of bytes to allocate.
 * \return Pointer to allocated memory on success, or `NULL` on failure.
 */
#define ICUDS_ALLOC(size) (malloc((size_t)size))

/**
 * \brief Free memory.
 * \param[in,out] ptr Pointer to memory to free.
 */
#define ICUDS_FREE(ptr) (free((void *)ptr))

#endif /* CUDS_INTERNAL_H */
