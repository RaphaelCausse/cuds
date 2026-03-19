/******************************************************************************
 * \file cuds_align.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library alignment.
 *****************************************************************************/

#ifndef CUDS_ALIGN_H
#define CUDS_ALIGN_H

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include "cuds/cuds_common.h"

/*****************************************************************************/
/* MACROS */
/*****************************************************************************/

/**
 * \brief Align a value upward to the next multiple of `alignment`.
 * \param[in] value Value to align.
 * \param[in] alignment Alignment boundary (must be a power of 2).
 * \return Aligned value.
 */
#define CUDS_ALIGN_UP(value, alignment) \
    (((size_t)(value) + ((size_t)(alignment) - 1)) & (~((size_t)(alignment) - 1)))

/**
 * \brief Align a value downward to the previous multiple of `alignment`.
 * \param[in] value Value to align.
 * \param[in] alignment Alignment boundary (must be a power of two).
 * \return Aligned value.
 */
#define CUDS_ALIGN_DOWN(value, alignment) \
    ((size_t)(value) & ~((size_t)(alignment) - 1))

#endif /* CUDS_ALIGN_H */