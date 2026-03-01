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
 * \typedef cuds_arena_t
 * \brief
 */
typedef struct
{
    size_t capacity;
    size_t offset;
} cuds_arena_t;

/*****************************************************************************/
/* FUNCTIONS */
/*****************************************************************************/

/**
 * \brief
 * \param[in] v_capacity
 * \return
 */
extern CUDS_API cuds_arena_t *cuds_arena_create(size_t v_capacity);

/**
 * \brief
 * \param[in] p_self
 * \return
 */
extern CUDS_API cuds_arena_t *cuds_arena_destroy(cuds_arena_t *p_self);

/**
 * \brief
 * \param[in] p_self
 * \param[in] v_size
 * \return
 */
extern CUDS_API void *cuds_arena_alloc(cuds_arena_t *p_self, size_t v_size);

/**
 * \brief
 * \param[in] p_self
 * \return
 */
extern CUDS_API size_t cuds_arena_remaining(cuds_arena_t *p_self);

/**
 * \brief
 * \param[in] p_self
 */
extern CUDS_API void cuds_arena_reset(cuds_arena_t *p_self);

#endif /* CUDS_ARENA_H */