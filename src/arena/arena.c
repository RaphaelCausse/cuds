/******************************************************************************
 * \file cuds_arena.c
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Implementation for CUDS library arena memory allocator.
 *****************************************************************************/

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include <string.h>
#include "cuds/cuds_arena.h"
#include "cuds/cuds_align.h"

/*****************************************************************************/
/* MACROS */
/*****************************************************************************/

/**
 * \brief
 */
#define CUDS_ARENA_BASE (sizeof(cuds_arena_t))

/**
 * \brief
 */
#define CUDS_ARENA_ALIGN (sizeof(void *))

/*****************************************************************************/
/* FUNCTIONS */
/*****************************************************************************/

cuds_arena_t *cuds_arena_create(size_t v_capacity)
{
    cuds_arena_t *p_arena = NULL;
    size_t v_alloc_size = CUDS_ARENA_BASE + v_capacity;

    p_arena = (cuds_arena_t *)malloc(v_alloc_size);
    if (p_arena == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }

    p_arena->capacity = v_capacity;
    p_arena->offset = 0;

    return p_arena;
}

cuds_arena_t *cuds_arena_destroy(cuds_arena_t *p_self)
{
    if (p_self != NULL)
    {
        free(p_self);
    }
    return NULL;
}

void *cuds_arena_alloc(cuds_arena_t *p_self, size_t v_size)
{
    if ((p_self == NULL) || (v_size == 0))
    {
        errno = EINVAL;
        return NULL;
    }

    void *p_memory_out = NULL;
    size_t v_offset_aligned = CUDS_ALIGN_UP(p_self->offset, CUDS_ARENA_ALIGN);

    if (v_size > (p_self->capacity - v_offset_aligned))
    {
        errno = ENOMEM;
        return NULL;
    }

    p_self->offset = v_offset_aligned + v_size;
    p_memory_out = (void *)((byte_t *)p_self + CUDS_ARENA_BASE + v_offset_aligned);
    memset(p_memory_out, 0, v_size);

    return p_memory_out;
}

size_t cuds_arena_remaining(cuds_arena_t *p_self)
{
    if (p_self == NULL)
    {
        return 0;
    }
    return (p_self->capacity - p_self->offset);
}

void cuds_arena_reset(cuds_arena_t *p_self)
{
    if (p_self == NULL)
    {
        return;
    }
    p_self->offset = 0;
}
