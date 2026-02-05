/******************************************************************************
 * \file value.c
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Implementation for CUDS generic value container.
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

CUDS_API bool cuds_value_is_type(const cuds_value_t *self, cuds_value_type_t type)
{
    return (self &&
            cuds_value_is_valid_type(type) &&
            cuds_value_is_valid_type(self->type) &&
            (self->type == type));
}

CUDS_API bool cuds_value_has_value(const cuds_value_t *self)
{
    return (self &&
            cuds_value_is_valid_type(self->type) &&
            (self->type != CUDS_VALUE_NONE));
}

CUDS_API bool cuds_value_has_value_of_type(const cuds_value_t *self, cuds_value_type_t type)
{
    return (self &&
            cuds_value_is_valid_type(type) &&
            cuds_value_is_valid_type(self->type) &&
            (self->type != CUDS_VALUE_NONE) &&
            (self->type == type));
}

CUDS_API void cuds_value_reset(cuds_value_t *self)
{
    assert(self);
    self->type = CUDS_VALUE_NONE;
    memset(&self->val, 0, sizeof(self->val));
}

CUDS_API int8_t cuds_value_i8(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_I8);
    return self->val.i8;
}

CUDS_API uint8_t cuds_value_u8(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_U8);
    return self->val.u8;
}

CUDS_API int16_t cuds_value_i16(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_I16);
    return self->val.i16;
}

CUDS_API uint16_t cuds_value_u16(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_U16);
    return self->val.u16;
}

CUDS_API int32_t cuds_value_i32(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_I32);
    return self->val.i32;
}

CUDS_API uint32_t cuds_value_u32(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_U32);
    return self->val.u32;
}

CUDS_API int64_t cuds_value_i64(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_I64);
    return self->val.i64;
}

CUDS_API uint64_t cuds_value_u64(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_U64);
    return self->val.u64;
}

CUDS_API float32_t cuds_value_f32(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_F32);
    return self->val.f32;
}

CUDS_API float64_t cuds_value_f64(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_F64);
    return self->val.f64;
}

CUDS_API bool cuds_value_bool(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_BOOL);
    return self->val.b;
}

CUDS_API void *cuds_value_ptr(const cuds_value_t *self)
{
    assert(self);
    assert(self->type == CUDS_VALUE_VPTR);
    return self->val.vptr;
}

CUDS_API void cuds_value_set_i8(cuds_value_t *self, int8_t new_value)
{
    assert(self);
    self->type = CUDS_VALUE_I8;
    self->val.i8 = new_value;
}

CUDS_API void cuds_value_set_u8(cuds_value_t *self, uint8_t new_value)
{
    assert(self);
    self->type = CUDS_VALUE_U8;
    self->val.u8 = new_value;
}

CUDS_API void cuds_value_set_i16(cuds_value_t *self, int16_t new_value)
{
    assert(self);
    self->type = CUDS_VALUE_I16;
    self->val.i16 = new_value;
}

CUDS_API void cuds_value_set_u16(cuds_value_t *self, uint16_t new_value)
{
    assert(self);
    self->type = CUDS_VALUE_U16;
    self->val.u16 = new_value;
}

CUDS_API void cuds_value_set_i32(cuds_value_t *self, int32_t new_value)
{
    assert(self);
    self->type = CUDS_VALUE_I32;
    self->val.i32 = new_value;
}

CUDS_API void cuds_value_set_u32(cuds_value_t *self, uint32_t new_value)
{
    assert(self);
    self->type = CUDS_VALUE_U32;
    self->val.u32 = new_value;
}

CUDS_API void cuds_value_set_i64(cuds_value_t *self, int64_t new_value)
{
    assert(self);
    self->type = CUDS_VALUE_I64;
    self->val.i64 = new_value;
}

CUDS_API void cuds_value_set_u64(cuds_value_t *self, uint64_t new_value)
{
    assert(self);
    self->type = CUDS_VALUE_U64;
    self->val.u64 = new_value;
}

CUDS_API void cuds_value_set_f32(cuds_value_t *self, float32_t new_value)
{
    assert(self);
    self->type = CUDS_VALUE_F32;
    self->val.f32 = new_value;
}

CUDS_API void cuds_value_set_f64(cuds_value_t *self, float64_t new_value)
{
    assert(self);
    self->type = CUDS_VALUE_F64;
    self->val.f64 = new_value;
}

CUDS_API void cuds_value_set_bool(cuds_value_t *self, bool new_value)
{
    assert(self);
    self->type = CUDS_VALUE_BOOL;
    self->val.b = new_value;
}

CUDS_API void cuds_value_set_ptr(cuds_value_t *self, const void *new_value)
{
    assert(self);
    self->type = CUDS_VALUE_VPTR;
    self->val.vptr = (void *)new_value;
}
