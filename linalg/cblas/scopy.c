/**************************************************************************
*
* File:          $RCSfile: scopy.c,v $
* Module:        BLAS function
* Part of:       Gandalf Library
*
* Revision:      $Revision: 1.4 $
* Last edited:   $Date: 2005/02/25 09:30:20 $
* Author:        $Author: pm $
* Copyright:     Modifications (c) 2000 Imagineer Software Limited
*
* Notes:         
* Private func:  
* History:       Modified from original CLAPACK source code 
*
**************************************************************************/

#include <math.h>
#include <gandalf/linalg/cblas/scopy.h>
#include <gandalf/common/misc_defs.h>
#include <gandalf/common/compare.h>
#include <gandalf/common/misc_error.h>

/* only define this function locally if there is no LAPACK installed */
#if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK)

Gan_Bool
 gan_scopy ( long n, float *dx, long incx, float *dy, long incy )
{
   long i;

   gan_err_test_bool ( n >= 0, "gan_scopy", GAN_ERROR_CBLAS_ILLEGAL_ARG, "" );

   if ( incx == 1 && incy == 1 )
      for ( i = n-1; i >= 0; i-- )
         *dy++ = *dx++;
   else if ( incx == 1 )
      for ( i = n-1; i >= 0; dy += incy, i-- )
         *dy = *dx++;
   else if ( incy == 1 )
      for ( i = n-1; i >= 0; dx += incx, i-- )
         *dy++ = *dx;
   else /* incx != 1 && incy != 1 */
      for ( i = n-1; i >= 0; dx += incx, dy += incy, i-- )
         *dy = *dx;

   /* success */
   return GAN_TRUE;
}

#endif /* #if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK) */
