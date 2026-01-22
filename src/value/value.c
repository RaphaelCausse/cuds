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

bool cuds_value_is_valid_type(cuds_value_type_t type)
{
    return ((type >= CUDS_VALUE_NONE) && (type < COUNT_CUDS_VALUE));
}

bool cuds_value_is_type(const cuds_value_t *value, cuds_value_type_t type)
{
    return (value &&
            cuds_value_is_valid_type(type) &&
            cuds_value_is_valid_type(value->type) &&
            (value->type == type));
}

bool cuds_value_has_value(const cuds_value_t *value)
{
    return (value &&
            cuds_value_is_valid_type(value->type) &&
            (value->type != CUDS_VALUE_NONE));
}

bool cuds_value_has_value_of_type(const cuds_value_t *value, cuds_value_type_t type)
{
    return (value &&
            cuds_value_is_valid_type(type) &&
            cuds_value_is_valid_type(value->type) &&
            (value->type != CUDS_VALUE_NONE) &&
            (value->type == type));
}

void cuds_value_reset(cuds_value_t *value)
{
    assert(value);
    value->type = CUDS_VALUE_NONE;
    memset(&value->val, 0, sizeof(value->val));
}

int8_t cuds_value_i8(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_I8);
    return value->val.i8;
}

uint8_t cuds_value_u8(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_U8);
    return value->val.u8;
}

int16_t cuds_value_i16(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_I16);
    return value->val.i16;
}

uint16_t cuds_value_u16(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_U16);
    return value->val.u16;
}

int32_t cuds_value_i32(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_I32);
    return value->val.i32;
}

uint32_t cuds_value_u32(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_U32);
    return value->val.u32;
}

int64_t cuds_value_i64(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_I64);
    return value->val.i64;
}

uint64_t cuds_value_u64(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_U64);
    return value->val.u64;
}

float cuds_value_f32(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_F32);
    return value->val.f32;
}

double cuds_value_f64(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_F64);
    return value->val.f64;
}

bool cuds_value_bool(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_BOOL);
    return value->val.b;
}

void *cuds_value_ptr(const cuds_value_t *value)
{
    assert(value);
    assert(value->type == CUDS_VALUE_VPTR);
    return value->val.vptr;
}

void cuds_value_set_i8(cuds_value_t *value, int8_t new_value)
{
    assert(value);
    value->type = CUDS_VALUE_I8;
    value->val.i8 = new_value;
}

void cuds_value_set_u8(cuds_value_t *value, uint8_t new_value)
{
    assert(value);
    value->type = CUDS_VALUE_U8;
    value->val.u8 = new_value;
}

void cuds_value_set_i16(cuds_value_t *value, int16_t new_value)
{
    assert(value);
    value->type = CUDS_VALUE_I16;
    value->val.i16 = new_value;
}

void cuds_value_set_u16(cuds_value_t *value, uint16_t new_value)
{
    assert(value);
    value->type = CUDS_VALUE_U16;
    value->val.u16 = new_value;
}

void cuds_value_set_i32(cuds_value_t *value, int32_t new_value)
{
    assert(value);
    value->type = CUDS_VALUE_I32;
    value->val.i32 = new_value;
}

void cuds_value_set_u32(cuds_value_t *value, uint32_t new_value)
{
    assert(value);
    value->type = CUDS_VALUE_U32;
    value->val.u32 = new_value;
}

void cuds_value_set_i64(cuds_value_t *value, int64_t new_value)
{
    assert(value);
    value->type = CUDS_VALUE_I64;
    value->val.i64 = new_value;
}

void cuds_value_set_u64(cuds_value_t *value, uint64_t new_value)
{
    assert(value);
    value->type = CUDS_VALUE_U64;
    value->val.u64 = new_value;
}

void cuds_value_set_f32(cuds_value_t *value, float new_value)
{
    assert(value);
    value->type = CUDS_VALUE_F32;
    value->val.f32 = new_value;
}

void cuds_value_set_f64(cuds_value_t *value, double new_value)
{
    assert(value);
    value->type = CUDS_VALUE_F64;
    value->val.f64 = new_value;
}

void cuds_value_set_bool(cuds_value_t *value, bool new_value)
{
    assert(value);
    value->type = CUDS_VALUE_BOOL;
    value->val.b = new_value;
}

void cuds_value_set_ptr(cuds_value_t *value, const void *new_value)
{
    assert(value);
    value->type = CUDS_VALUE_VPTR;
    value->val.vptr = (void *)new_value;
}
