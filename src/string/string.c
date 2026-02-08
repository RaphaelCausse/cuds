/******************************************************************************
 * \file string.c
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Implementations for CUDS dynamic string.
 *****************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>
#include "cuds/string.h"
#include "string_internal.h"

//-----------------------------------------------------------------------------
// Functions definitions
//-----------------------------------------------------------------------------

CUDS_API cuds_string_t cuds_string_new(const char *init_cstr)
{
    size_t init_length = (init_cstr == NULL) ? 0 : strlen(init_cstr);
    return icuds_string_init(init_cstr, init_length);
}

CUDS_API void cuds_string_free(cuds_string_t self)
{
    if (self == NULL)
    {
        return;
    }
    free(ICUDS_STRING_HEADER(self));
}

CUDS_API void cuds_string_destroy(cuds_string_t *p_self)
{
    cuds_string_free(*p_self);
    *p_self = NULL;
}

CUDS_API size_t cuds_string_len(cuds_string_t self)
{
    icuds_string_header_t *p_string_header = ICUDS_STRING_HEADER(self);
    return p_string_header->length;
}