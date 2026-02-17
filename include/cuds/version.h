/******************************************************************************
 * \file version.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library version.
 *****************************************************************************/

#ifndef CUDS_VERSION_H
#define CUDS_VERSION_H

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <stdint.h>
#include "cuds/export.h"

//-----------------------------------------------------------------------------
// Version
//-----------------------------------------------------------------------------

/**
 * \brief The current major version of CUDS library.
 */
#define CUDS_VERSION_MAJOR 0

/**
 * \brief The current minor version of CUDS library.
 */
#define CUDS_VERSION_MINOR 0

/**
 * \brief The current patch version of CUDS library.
 */
#define CUDS_VERSION_PATCH 0

/**
 * \brief The current version suffix of CUDS library.
 */
#define CUDS_VERSION_SUFFIX ""

//-----------------------------------------------------------------------------
// Numerical and string helpers
//-----------------------------------------------------------------------------

/**
 * \brief Pack version components into a 32-bit unsigned integer.
 */
#define CUDS_VERSIONNUM(major, minor, patch) \
    (((uint32_t)(major) << 16) |             \
     ((uint32_t)(minor) << 8) |              \
     ((uint32_t)(patch)))

/**
 * \brief Extract the major version from a numeric version.
 */
#define CUDS_VERSIONNUM_MAJOR(version) \
    ((uint8_t)(((version) >> 16) & 0xFF))

/**
 * \brief Extract the minor version from a numeric version.
 */
#define CUDS_VERSIONNUM_MINOR(version) \
    ((uint8_t)(((version) >> 8) & 0xFF))

/**
 * \brief Extract the patch version from a numeric version.
 */
#define CUDS_VERSIONNUM_PATCH(version) \
    ((uint8_t)((version) & 0xFF))

/**
 * \brief Converts a token into a string literal (helper macro, do not use directly).
 */
#define CUDS_STRINGIFY_HELPER(x) #x

/**
 * \brief Converts a macro or token into a string literal.
 */
#define CUDS_STRINGIFY(x) CUDS_STRINGIFY_HELPER(x)

//-----------------------------------------------------------------------------
// Current version and revision
//-----------------------------------------------------------------------------

/**
 * \brief Numeric version of the current CUDS library.
 */
#define CUDS_VERSION \
    CUDS_VERSIONNUM(CUDS_VERSION_MAJOR, CUDS_VERSION_MINOR, CUDS_VERSION_PATCH)

/**
 * \brief Human-readable version string of the CUDS library.
 * The format is "MAJOR.MINOR.PATCH SUFFIX".
 */
#define CUDS_VERSION_STRING \
    (CUDS_STRINGIFY(CUDS_VERSION_MAJOR) "." CUDS_STRINGIFY(CUDS_VERSION_MINOR) "." CUDS_STRINGIFY(CUDS_VERSION_PATCH) CUDS_VERSION_SUFFIX)

/**
 * \brief Evaluate to true if CUDS is at least of version X.Y.Z.
 */
#define CUDS_VERSION_ATLEAST(x, y, z) \
    (CUDS_VERSION >= CUDS_VERSIONNUM((x), (y), (z)))

/**
 * \brief Source control revision string of the CUDS library.
 * This string is embedded into the compiled library at build time and
 * identifies the source revision used to produce the binary.
 */
// extern CUDS_API const char *CUDS_REVISION;
extern const char *CUDS_REVISION;

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

/**
 * \brief Get the version of CUDS that is linked against your program.
 * \return Numeric version of CUDS as 32-bit integer.
 * \note If you are linking to CUDS dynamically, then it is possible that the current
 * version will be different than the version you compiled against.
 * This * function returns the current version, while CUDS_VERSION is the version you
 * compiled with.
 */
CUDS_API uint32_t cuds_version(void);

#endif /* CUDS_VERSION_H */