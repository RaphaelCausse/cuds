/******************************************************************************
 * \file string_internal.c
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Internal implementations for CUDS dynamic string.
 *****************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <string.h>
#include "string_internal.h"

//-----------------------------------------------------------------------------
// Functions definitions
//-----------------------------------------------------------------------------

cuds_string_t icuds_string_init(const char *init_cstr, size_t init_length)
{
    icuds_string_header_t *p_header = NULL;
    cuds_string_t string = NULL;

    size_t header_size = sizeof(*p_header);
    size_t alloc_size = header_size + init_length + 1;

    p_header = (icuds_string_header_t *)ICUDS_ALLOC(alloc_size);
    if (p_header == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }

    if (init_cstr == NULL)
    {
        memset(p_header, 0, alloc_size);
    }

    p_header->length = init_length;
    p_header->alloc = init_length;

    string = (cuds_string_t)p_header->buffer;
    if ((init_cstr != NULL) && (init_length != 0))
    {
        memcpy(string, init_cstr, init_length);
    }

    string[init_length] = '\0';

    return string;
}
