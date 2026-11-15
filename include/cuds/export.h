/******************************************************************************
 * \file export.h
 * \package cuds
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Declarations for symbol visibility and C++ linkage of CUDS library.
 *
 * Build modes:
 *  - static library : nothing to define, CUDS_API is empty.
 *  - shared library : `_CUDS_SHARED` must be defined by the user of the library.
 *                     `_CUDS_BUILDING` is defined only while building the
 *                     shared library itself (done by the Makefile).
 *****************************************************************************/

#ifndef CUDS_EXPORT_H
#define CUDS_EXPORT_H

/*****************************************************************************/
/* SYMBOL VISIBILITY */
/*****************************************************************************/

/**
 * \brief Marks a symbol as part of the public ABI of the shared library.
 */
#if defined(_CUDS_SHARED)
#if defined(_WIN32) || defined(__CYGWIN__)
#if defined(_CUDS_BUILDING)
#define CUDS_API __declspec(dllexport)
#else
#define CUDS_API __declspec(dllimport)
#endif /* _CUDS_BUILDING */
#elif defined(__GNUC__) || defined(__clang__)
#define CUDS_API __attribute__((visibility("default")))
#else
#define CUDS_API
#endif /*_WIN32  */
#else
#define CUDS_API
#endif /* _CUDS_SHARED */

/*****************************************************************************/
/* C++ LINKAGE */
/*****************************************************************************/

/**
 * \brief Wrap public declarations so the library is usable from C++.
 */
#ifdef __cplusplus
#define CUDS_EXTERN_C_BEGIN \
    extern "C"              \
    {
#define CUDS_EXTERN_C_END }
#else
#define CUDS_EXTERN_C_BEGIN
#define CUDS_EXTERN_C_END
#endif

#endif /* CUDS_EXPORT_H */
