/******************************************************************************
 * \file version.h
 * \package cuds
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Declarations for compile-time and runtime version of CUDS library.
 *****************************************************************************/

#ifndef CUDS_VERSION_H
#define CUDS_VERSION_H

/*****************************************************************************/
/* INCLUDES */
/*****************************************************************************/

#include <stdint.h>
#include <stdbool.h>

#include "cuds/export.h"

/*****************************************************************************/
/* CURRENT VERSION (single source of truth) */
/*****************************************************************************/

/**
 * \brief The current major version of the CUDS library.
 */
#define CUDS_VERSION_MAJOR 0

/**
 * \brief The current minor version of the CUDS library.
 */
#define CUDS_VERSION_MINOR 1

/**
 * \brief The current patch version of the CUDS library.
 */
#define CUDS_VERSION_PATCH 0

/**
 * \brief Version suffix, empty for a release.
 */
#define CUDS_VERSION_SUFFIX ""

/*****************************************************************************/
/* NUMERIC VERSION */
/*****************************************************************************/

/*
 * The macros below use no cast on purpose, so that they can be evaluated by
 * the preprocessor (`#if CUDS_VERSION_ATLEAST(0, 2, 0)`). Each component is
 * limited to 0..255.
 */

/**
 * \brief Pack version components into a single integer (0xMMmmpp).
 * \param[in] major Major version (0..255).
 * \param[in] minor Minor version (0..255).
 * \param[in] patch Patch version (0..255).
 */
#define CUDS_VERSIONNUM(major, minor, patch) \
    ((((major) & 0xFF) << 16) | (((minor) & 0xFF) << 8) | ((patch) & 0xFF))

/**
 * \brief Extract the major component from a packed version.
 */
#define CUDS_VERSIONNUM_MAJOR(version) \
    (((version) >> 16) & 0xFF)

/**
 * \brief Extract the minor component from a packed version.
 */
#define CUDS_VERSIONNUM_MINOR(version) \
    (((version) >> 8) & 0xFF)

/**
 * \brief Extract the patch component from a packed version.
 */
#define CUDS_VERSIONNUM_PATCH(version) \
    ((version) & 0xFF)

/**
 * \brief Numeric version of the headers being compiled against.
 */
#define CUDS_VERSION \
    CUDS_VERSIONNUM(CUDS_VERSION_MAJOR, CUDS_VERSION_MINOR, CUDS_VERSION_PATCH)

/**
 * \brief Evaluate to true if the headers are at least of version X.Y.Z.
 */
#define CUDS_VERSION_ATLEAST(x, y, z) \
    (CUDS_VERSION >= CUDS_VERSIONNUM((x), (y), (z)))

/**
 * \brief Convenience version check between linked and compiled library.
 */
#define CUDS_CHECK_VERSION() \
    cuds_version_is_compatible((uint32_t)CUDS_VERSION)

/*****************************************************************************/
/* STRING VERSION */
/*****************************************************************************/

/** \cond INTERNAL */
#define _CUDS_VERSION_STR(x) #x
#define _CUDS_VERSION_XSTR(x) _CUDS_VERSION_STR(x)
/** \endcond */

/**
 * \brief Version string literal "MAJOR.MINOR.PATCH" with the suffix.
 */
#define CUDS_VERSION_STRING \
    _CUDS_VERSION_XSTR(CUDS_VERSION_MAJOR)     \
    "." _CUDS_VERSION_XSTR(CUDS_VERSION_MINOR) \
    "." _CUDS_VERSION_XSTR(CUDS_VERSION_PATCH) \
    CUDS_VERSION_SUFFIX

/*****************************************************************************/
/* FUNCTIONS */
/*****************************************************************************/

CUDS_EXTERN_C_BEGIN

/**
 * \brief Get the numeric version of the CUDS library that is linked against.
 * \return Packed version, to decode with CUDS_VERSIONNUM_MAJOR() & co.
 * \note With the shared library this can differ from CUDS_VERSION, which is
 * the version of the headers used at compile time.
 */
CUDS_API uint32_t cuds_version(void);

/**
 * \brief Get the version string of the CUDS library that is linked against.
 * \return "MAJOR.MINOR.PATCH[SUFFIX]", never NULL.
 */
CUDS_API const char *cuds_version_string(void);

/**
 * \brief Get the source revision the library was built from.
 * \return Short git hash given at build time, or "unknown", never NULL.
 */
CUDS_API const char *cuds_revision(void);

/**
 * \brief Check that the linked library is ABI-compatible with a compiled version.
 * \param[in] compiled Numeric version the program was compiled against (CUDS_VERSION).
 * \return true if compatible, false otherwise.
 */
CUDS_API bool cuds_version_is_compatible(uint32_t compiled);

CUDS_EXTERN_C_END

#endif /* CUDS_VERSION_H */
