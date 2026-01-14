/******************************************************************************
 * \file version.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Public header for CUDS library version module.
 *****************************************************************************/

#ifndef _CUDS_VERSION_H_
#define _CUDS_VERSION_H_

//-----------------------------------------------------------------------------
// Version components
//-----------------------------------------------------------------------------

/**
 * The current major version of CUDS headers.
 */
#define CUDS_VERSION_MAJOR 0

/**
 * The current minor version of CUDS headers.
 */
#define CUDS_VERSION_MINOR 0

/**
 * The current patch version of CUDS headers.
 */
#define CUDS_VERSION_PATCH 0

//-----------------------------------------------------------------------------
// Numeric version helpers
//-----------------------------------------------------------------------------

/**
 * Turn version numbers into a numeric value.
 */
#define CUDS_VERSIONNUM(major, minor, patch) \
    ((major) * 1000000 + (minor) * 1000 + (patch))

/**
 * Extract the major version from a numeric version.
 */
#define CUDS_VERSIONNUM_MAJOR(version) \
    ((version) / 1000000)

/**
 * Extract the minor version from a numeric version.
 */
#define CUDS_VERSIONNUM_MINOR(version) \
    (((version) / 1000) % 1000)

/**
 * Extract the patch version from a numeric version.
 */
#define CUDS_VERSIONNUM_PATCH(version) \
    ((version) % 1000)

//-----------------------------------------------------------------------------
// Current version
//-----------------------------------------------------------------------------

/**
 * Numeric version of the current CUDS headers.
 */
#define CUDS_VERSION                    \
    CUDS_VERSIONNUM(CUDS_VERSION_MAJOR, \
                    CUDS_VERSION_MINOR, \
                    CUDS_VERSION_PATCH)

/**
 * Evaluate to true if CUDS is at least of version X.Y.Z.
 */
#define CUDS_VERSION_ATLEAST(x, y, z) \
    (CUDS_VERSION >= CUDS_VERSIONNUM((x), (y), (z)))

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

/**
 * \brief Get the version of CUDS that is linked against your program.
 * \return Numeric version of CUDS.
 *
 * \note If you are linking to CUDS dynamically, then it is possible that the current
 * version will be different than the version you compiled against. This
 * function returns the current version, while CUDS_VERSION is the version you
 * compiled with.
 */
extern int cuds_version_get(void);

#endif /* _CUDS_VERSION_H_ */