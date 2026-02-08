/******************************************************************************
 * \file value.c
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Implementations for CUDS generic value container.
 *****************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "cuds/value.h"

//-----------------------------------------------------------------------------
// Functions definitions
//-----------------------------------------------------------------------------

CUDS_API bool cuds_value_is_valid_type(cuds_value_type_t type)
{
    return ((type >= CUDS_VALUE_NONE) && (type < COUNT_CUDS_VALUE));
}

CUDS_API bool cuds_value_is_type(const cuds_value_t *p_self, cuds_value_type_t type)
{
    return (p_self &&
            cuds_value_is_valid_type(type) &&
            cuds_value_is_valid_type(p_self->type) &&
            (p_self->type == type));
}

CUDS_API bool cuds_value_has_value(const cuds_value_t *p_self)
{
    return (p_self &&
            cuds_value_is_valid_type(p_self->type) &&
            (p_self->type != CUDS_VALUE_NONE));
}

CUDS_API bool cuds_value_has_value_of_type(const cuds_value_t *p_self, cuds_value_type_t type)
{
    return (p_self &&
            cuds_value_is_valid_type(type) &&
            cuds_value_is_valid_type(p_self->type) &&
            (p_self->type != CUDS_VALUE_NONE) &&
            (p_self->type == type));
}

CUDS_API void cuds_value_reset(cuds_value_t *p_self)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_NONE;
    memset(&p_self->val, 0, sizeof(p_self->val));
}

CUDS_API int8_t cuds_value_i8(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_I8);
    return p_self->val.i8;
}

CUDS_API uint8_t cuds_value_u8(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_U8);
    return p_self->val.u8;
}

CUDS_API int16_t cuds_value_i16(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_I16);
    return p_self->val.i16;
}

CUDS_API uint16_t cuds_value_u16(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_U16);
    return p_self->val.u16;
}

CUDS_API int32_t cuds_value_i32(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_I32);
    return p_self->val.i32;
}

CUDS_API uint32_t cuds_value_u32(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_U32);
    return p_self->val.u32;
}

CUDS_API int64_t cuds_value_i64(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_I64);
    return p_self->val.i64;
}

CUDS_API uint64_t cuds_value_u64(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_U64);
    return p_self->val.u64;
}

CUDS_API float32_t cuds_value_f32(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_F32);
    return p_self->val.f32;
}

CUDS_API float64_t cuds_value_f64(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_F64);
    return p_self->val.f64;
}

CUDS_API bool cuds_value_bool(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_BOOL);
    return p_self->val.b;
}

CUDS_API void *cuds_value_ptr(const cuds_value_t *p_self)
{
    assert(p_self);
    assert(p_self->type == CUDS_VALUE_VPTR);
    return p_self->val.vptr;
}

CUDS_API void cuds_value_set_i8(cuds_value_t *p_self, int8_t new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_I8;
    p_self->val.i8 = new_value;
}

CUDS_API void cuds_value_set_u8(cuds_value_t *p_self, uint8_t new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_U8;
    p_self->val.u8 = new_value;
}

CUDS_API void cuds_value_set_i16(cuds_value_t *p_self, int16_t new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_I16;
    p_self->val.i16 = new_value;
}

CUDS_API void cuds_value_set_u16(cuds_value_t *p_self, uint16_t new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_U16;
    p_self->val.u16 = new_value;
}

CUDS_API void cuds_value_set_i32(cuds_value_t *p_self, int32_t new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_I32;
    p_self->val.i32 = new_value;
}

CUDS_API void cuds_value_set_u32(cuds_value_t *p_self, uint32_t new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_U32;
    p_self->val.u32 = new_value;
}

CUDS_API void cuds_value_set_i64(cuds_value_t *p_self, int64_t new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_I64;
    p_self->val.i64 = new_value;
}

CUDS_API void cuds_value_set_u64(cuds_value_t *p_self, uint64_t new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_U64;
    p_self->val.u64 = new_value;
}

CUDS_API void cuds_value_set_f32(cuds_value_t *p_self, float32_t new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_F32;
    p_self->val.f32 = new_value;
}

CUDS_API void cuds_value_set_f64(cuds_value_t *p_self, float64_t new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_F64;
    p_self->val.f64 = new_value;
}

CUDS_API void cuds_value_set_bool(cuds_value_t *p_self, bool new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_BOOL;
    p_self->val.b = new_value;
}

CUDS_API void cuds_value_set_ptr(cuds_value_t *p_self, const void *new_value)
{
    assert(p_self);
    p_self->type = CUDS_VALUE_VPTR;
    p_self->val.vptr = (void *)new_value;
}
