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

//-----------------------------------------------------------------------------
// Types definitions
//-----------------------------------------------------------------------------

/**
 * \struct icuds_string_header_t
 * \brief
 */
typedef struct
{
    size_t length; /**< */
    size_t alloc;  /**< */
    char buffer[]; /**< */
} icuds_string_header_t;

//-----------------------------------------------------------------------------
// Macros definitions
//-----------------------------------------------------------------------------

#define ICUDS_STRING_HEADER(str) \
    ((icuds_string_header_t *)((str) - (sizeof(icuds_string_header_t))))

//-----------------------------------------------------------------------------
// Functions declarations
//-----------------------------------------------------------------------------

/**
 * \brief
 * \param[in] init_cstr
 * \param[in] init_length
 * \return
 */
cuds_string_t icuds_string_init(const char *init_cstr, size_t init_length);

#endif /* CUDS_STRING_INTERNAL_H */
