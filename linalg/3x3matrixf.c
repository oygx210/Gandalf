/**
 * File:          $RCSfile: 3x3matrixf.c,v $
 * Module:        3x3 matrices (single precision)
 * Part of:       Gandalf Library
 *
 * Revision:      $Revision: 1.7 $
 * Last edited:   $Date: 2002/04/18 14:56:23 $
 * Author:        $Author: pm $
 * Copyright:     (c) 2000 Imagineer Software Limited
 */

/* This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <math.h>
#include <string.h>
#include <gandalf/linalg/3x3matrixf.h>
#include <gandalf/common/misc_error.h>

/**
 * \addtogroup LinearAlgebra
 * \{
 */

/**
 * \addtogroup FixedSizeMatVec
 * \{
 */

/**
 * \addtogroup FixedSizeMatrix
 * \{
 */

/* include the functions specific to generic, symmetric and triangular
   3x3 matrices. */
#include <gandalf/linalg/3x3matf_noc.c>
#include <gandalf/linalg/3x3symmatf_noc.c>
#include <gandalf/linalg/3x3ltmatf_noc.c>

/* define all the standard small matrix functions for generic 3x3 matrices */
#include <gandalf/linalg/3x3matf_noc.h>
#include <gandalf/linalg/squmatrixf_noc.c>
#include <gandalf/linalg/matrixf_noc.c>

/* define all the standard small matrix functions for symmetric 3x3 matrices */
#include <gandalf/linalg/3x3symmatf_noc.h>
#include <gandalf/linalg/symmatrixf_noc.c>
#include <gandalf/linalg/squmatrixf_noc.c>
#include <gandalf/linalg/matrixf_noc.c>

/* define all the standard small matrix functions for lower triangular
   matrices */
#include <gandalf/linalg/3x3ltmatf_noc.h>
#include <gandalf/linalg/squmatrixf_noc.c>
#include <gandalf/linalg/matrixf_noc.c>

/* define all the standard small matrix functions for upper triangular
   matrices */
#include <gandalf/linalg/3x3ltmatTf_noc.h>
#include <gandalf/linalg/squmatrixf_noc.c>
#include <gandalf/linalg/matrixf_noc.c>

/**
 * \}
 */

/**
 * \}
 */

/**
 * \}
 */
