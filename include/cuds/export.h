/******************************************************************************
 * \file export.h
 * \author Raphael CAUSSE
 * \brief Symbol visibility and export macros for CUDS.
 *****************************************************************************/

#ifndef CUDS_EXPORT_H
#define CUDS_EXPORT_H

#if defined(_WIN32)
  #if defined(CUDS_SHARED)
    #if defined(CUDS_SHARED_EXPORT)
      #define CUDS_API __declspec(dllexport)
    #else /* CUDS_SHARED_EXPORT */
      #define CUDS_API __declspec(dllimport)
    #endif /* CUDS_SHARED_EXPORT */
  #else  /* CUDS_SHARED */
    #define CUDS_API
  #endif /* CUDS_SHARED */
#else  /* _WIN32 */
  #define CUDS_API
#endif /* _WIN32 */

#endif /* CUDS_EXPORT_H */
