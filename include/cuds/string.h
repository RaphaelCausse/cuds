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
 * \brief
 */
typedef char *cuds_string_t;

//-----------------------------------------------------------------------------
// Functions declarations
//-----------------------------------------------------------------------------

/**
 * \brief
 * \param[in] init_cstr
 * \return
 */
CUDS_API cuds_string_t cuds_string_new(const char *init_cstr);

/**
 * \brief
 * \param[in] self
 */
CUDS_API void cuds_string_free(cuds_string_t self);

/**
 * \brief
 * \param[in] p_self
 */
CUDS_API void cuds_string_destroy(cuds_string_t *p_self);

/**
 * \brief
 * \param[in] self
 * \return
 */
CUDS_API size_t cuds_string_len(cuds_string_t self);

#endif /* CUDS_STRING_H */
