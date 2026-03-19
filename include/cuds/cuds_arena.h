/******************************************************************************
 * \file cuds_arena.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library arena memory allocator.
 *****************************************************************************/

#ifndef CUDS_ARENA_H
#define CUDS_ARENA_H

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include "cuds/cuds_common.h"
#include "cuds/cuds_units.h"

/*****************************************************************************/
/* TYPES */
/*****************************************************************************/

/**
 * \struct cuds_arena_t
 * \brief Arena memory allocator structure.
 *
 * Memory layout:
 *   +----------------------+
 *   | cuds_arena_t header  |
 *   +----------------------+
 *   | usable memory block  |
 *   +----------------------+
 */
typedef struct
{
    size_t capacity; /**< Total usable capacity in bytes. */
    size_t offset;   /**< Current allocation offset in bytes. */
} cuds_arena_t;

/*****************************************************************************/
/* FUNCTIONS */
/*****************************************************************************/

/**
 * \brief Create a new arena allocator and allocate memory.
 * \param[in] v_capacity Capacity of arena in bytes.
 * \return Pointer to a newly created arena on success, otherwise `NULL` on failure.
 * \note `errno` is set to ENOMEM on allocation failure.
 */
extern CUDS_API cuds_arena_t *cuds_arena_create(size_t v_capacity);

/**
 * \brief Destroy an arena and release its memory.
 * \param[in] p_self Pointer to arena instance.
 * \return `NULL`, to set back pointer to arena to prevent use after-free.
 * \note `errno` is set to EINVAL if `p_self` is `NULL`.
 * \warning All pointers previously returned by `cuds_arena_alloc` become invalid after this call.
 */
extern CUDS_API cuds_arena_t *cuds_arena_destroy(cuds_arena_t *p_self);

/**
 * \brief Allocate and zero-initialize memory from an arena.
 * \param[in] p_self Pointer to arena instance.
 * \param[in] v_size Number of bytes to allocate.
 * \return Pointer to allocated memory on success, otherwise `NULL` on failure.
 * \note `errno` is set to EINVAL if `p_self` is `NULL` or `v_size` is 0, and ENOMEM if not enough remaining space.
 * \note Allocated memory remains valid until the arena is reset or destroyed.
 */
extern CUDS_API void *cuds_arena_alloc(cuds_arena_t *p_self, size_t v_size);

/**
 * \brief Get remaining free space in the arena.
 * \param[in] p_self Pointer to arena instance.
 * \return Number of remaining free bytes.
 * \note `errno` is set to EINVAL if `p_self` is `NULL`.
 */
extern CUDS_API size_t cuds_arena_remaining(cuds_arena_t *p_self);

/**
 * \brief Resets the arena without releasing memory.
 * \param[in] p_self Pointer to arena instance.
 */
extern CUDS_API void cuds_arena_reset(cuds_arena_t *p_self);

#endif /* CUDS_ARENA_H */