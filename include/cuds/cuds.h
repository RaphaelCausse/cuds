/******************************************************************************
 * \file cuds.h
 * \author Raphael CAUSSE (raphael.causse2@gmail.com)
 * \brief Main public header for CUDS library.
 *****************************************************************************/

#ifndef CUDS_H
#define CUDS_H

//-----------------------------------------------------------------------------
// Check minimum C standard
//-----------------------------------------------------------------------------

#if !defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L)
  #error "CUDS requires at least C99 standard"
#endif

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "cuds/version.h"
#include "cuds/platform.h"
#include "cuds/types.h"

#include "cuds/algorithm.h"
#include "cuds/units.h"

#endif /* CUDS_H */