/******************************************************************************
 * \file string_internal.c
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Internal implementations for CUDS dynamic string.
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

cuds_string_t icuds_string_init(const char *init_cstr, size_t init_length)
{
    icuds_string_header_t *p_string_header = NULL;
    cuds_string_t string = NULL;

    size_t header_size = sizeof(*p_string_header);
    size_t alloc_size = header_size + init_length + 1;

    p_string_header = (icuds_string_header_t *)malloc(alloc_size);
    if (!p_string_header)
    {
        return NULL;
    }

    if (!init_cstr)
    {
        memset(p_string_header, 0, alloc_size);
    }

    p_string_header->length = init_length;
    p_string_header->alloc = init_length;

    string = (cuds_string_t)p_string_header->buffer;
    if (init_cstr && init_length)
    {
        memcpy(string, init_cstr, init_length);
    }
    string[init_length] = '\0';

    return string;
}
