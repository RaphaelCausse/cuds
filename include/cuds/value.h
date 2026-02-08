/******************************************************************************
 * \file value.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS generic value container.
 *
 * This header defines a generic, type-tagged value container (cuds_value_t)
 * and functions to set, get, reset, and inspect its content.
 *****************************************************************************/

#ifndef CUDS_VALUE_H
#define CUDS_VALUE_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "cuds/export.h"
#include "cuds/types.h"

//-----------------------------------------------------------------------------
// Types definitions
//-----------------------------------------------------------------------------

/**
 * \enum cuds_value_type_t
 * \brief Enumerates the supported value types.
 */
typedef enum
{
    CUDS_VALUE_NONE = 0, /**< No value */
    CUDS_VALUE_I8,       /**< int8_t value */
    CUDS_VALUE_U8,       /**< uint8_t value */
    CUDS_VALUE_I16,      /**< int16_t value */
    CUDS_VALUE_U16,      /**< uint16_t value */
    CUDS_VALUE_I32,      /**< int32_t value */
    CUDS_VALUE_U32,      /**< uint32_t value */
    CUDS_VALUE_I64,      /**< int64_t value */
    CUDS_VALUE_U64,      /**< uint64_t value */
    CUDS_VALUE_F32,      /**< float32_t value */
    CUDS_VALUE_F64,      /**< float64_t value */
    CUDS_VALUE_BOOL,     /**< bool value */
    CUDS_VALUE_VPTR,     /**< void* value */
    COUNT_CUDS_VALUE,    /**< Count enumeration, for bounds checking */
} cuds_value_type_t;

/**
 * \struct cuds_value_t
 * \brief Structure storing a typed value.
 */
typedef struct
{
    cuds_value_type_t type; /**< Current value type stored */
    union
    {
        int8_t i8;
        uint8_t u8;
        int16_t i16;
        uint16_t u16;
        int32_t i32;
        uint32_t u32;
        int64_t i64;
        uint64_t u64;
        float32_t f32;
        float64_t f64;
        bool b;
        void *vptr;
    } val; /**< Actual stored value */
} cuds_value_t;

//-----------------------------------------------------------------------------
// Functions declarations
//-----------------------------------------------------------------------------

/**
 * \brief Checks if a type is within the valid range of the enum.
 * \param[in] type Type to check
 * \return `true` if valid, `false` otherwise.
 */
CUDS_API bool cuds_value_is_valid_type(cuds_value_type_t type);

/**
 * \brief Checks if the value structure is of the specified type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] type Expected type
 * \return `true` if value is not NULL, type is valid and matches, `false` otherwise.
 */
CUDS_API bool cuds_value_is_type(const cuds_value_t *p_self, cuds_value_type_t type);

/**
 * \brief Checks if the value structure contains a meaningful value (not NONE).
 * \param[in] p_self Pointer to the value structure
 * \return `true` if the value is valid and type != NONE, `false` otherwise.
 */
CUDS_API bool cuds_value_has_value(const cuds_value_t *p_self);

/**
 * \brief Checks if the value contains a meaningful value of a specific type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] type Expected type
 * \return `true` if value is valid, has a value, and matches the type, `false` otherwise.
 */
CUDS_API bool cuds_value_has_value_of_type(const cuds_value_t *p_self, cuds_value_type_t type);

/**
 * \brief Resets the content of the value structure.
 * \param[in] p_self Pointer to the value structure
 */
CUDS_API void cuds_value_reset(cuds_value_t *p_self);

/**
 * \brief Gets an int8_t from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored int8_t.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API int8_t cuds_value_i8(const cuds_value_t *p_self);

/**
 * \brief Gets a uint8_t from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored uint8_t.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API uint8_t cuds_value_u8(const cuds_value_t *p_self);

/**
 * \brief Gets an int16_t from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored int16_t.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API int16_t cuds_value_i16(const cuds_value_t *p_self);

/**
 * \brief Gets a uint16_t from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored uint16_t.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API uint16_t cuds_value_u16(const cuds_value_t *p_self);

/**
 * \brief Gets an int32_t from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored int32_t.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API int32_t cuds_value_i32(const cuds_value_t *p_self);

/**
 * \brief Gets a uint32_t from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored uint32_t.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API uint32_t cuds_value_u32(const cuds_value_t *p_self);

/**
 * \brief Gets an int64_t from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored int64_t.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API int64_t cuds_value_i64(const cuds_value_t *p_self);

/**
 * \brief Gets a uint64_t from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored uint64_t.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API uint64_t cuds_value_u64(const cuds_value_t *p_self);

/**
 * \brief Gets a float32_t from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored float32_t.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API float32_t cuds_value_f32(const cuds_value_t *p_self);

/**
 * \brief Gets a float64_t from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored float64_t.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API float64_t cuds_value_f64(const cuds_value_t *p_self);

/**
 * \brief Gets a bool from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored bool.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API bool cuds_value_bool(const cuds_value_t *p_self);

/**
 * \brief Gets a void pointer from the value structure.
 * \param[in] p_self Pointer to the value structure
 * \return Stored void*.
 * \note Asserts if `value` is NULL or type mismatch.
 */
CUDS_API void *cuds_value_ptr(const cuds_value_t *p_self);

/**
 * \brief Sets an int8_t in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value int8_t to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_i8(cuds_value_t *p_self, int8_t new_value);

/**
 * \brief Sets a uint8_t in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value uint8_t to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_u8(cuds_value_t *p_self, uint8_t new_value);

/**
 * \brief Sets an int16_t in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value int16_t to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_i16(cuds_value_t *p_self, int16_t new_value);

/**
 * \brief Sets a uint16_t in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value uint16_t to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_u16(cuds_value_t *p_self, uint16_t new_value);

/**
 * \brief Sets an int32_t in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value int32_t to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_i32(cuds_value_t *p_self, int32_t new_value);

/**
 * \brief Sets a uint32_t in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value uint32_t to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_u32(cuds_value_t *p_self, uint32_t new_value);

/**
 * \brief Sets an int64_t in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value int64_t to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_i64(cuds_value_t *p_self, int64_t new_value);

/**
 * \brief Sets a uint64_t in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value uint64_t to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_u64(cuds_value_t *p_self, uint64_t new_value);

/**
 * \brief Sets a float32_t (float) in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value float32_t to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_f32(cuds_value_t *p_self, float32_t new_value);

/**
 * \brief Sets a float64_t (double) in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value float64_t to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_f64(cuds_value_t *p_self, float64_t new_value);

/**
 * \brief Sets a bool in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] new_value bool to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_bool(cuds_value_t *p_self, bool new_value);

/**
 * \brief Sets a void pointer in the value structure and updates type.
 * \param[in] p_self Pointer to the value structure
 * \param[in] p_self Pointer to store
 * \note Asserts if `value` is NULL.
 */
CUDS_API void cuds_value_set_ptr(cuds_value_t *p_self, const void *new_value);

#endif /* CUDS_VALUE_H */
