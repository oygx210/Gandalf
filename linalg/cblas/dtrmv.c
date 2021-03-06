/**************************************************************************
*
* File:          $RCSfile: dtrmv.c,v $
* Module:        BLAS function
* Part of:       Gandalf Library
*
* Revision:      $Revision: 1.6 $
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
#include <gandalf/linalg/cblas/dtrmv.h>
#include <gandalf/common/misc_defs.h>
#include <gandalf/common/compare.h>
#include <gandalf/common/misc_error.h>

/* only define this function locally if there is no LAPACK installed */
#if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK)

Gan_Bool
 gan_dtrmv ( Gan_LapackUpLoFlag upper, Gan_TposeFlag trans,
             Gan_LapackUnitFlag unit,
             long n, double *a, long lda, double *x, long incx )
{
   long i, j;
   double temp;

   if ( !upper ) return GAN_FALSE;
   if ( trans ) return GAN_FALSE;

   if ( n == 0 ) return GAN_TRUE;
   
   if ( incx == 1 )
      for ( j = 0; j < n; j++ )
      {
         if ( x[j] != 0.0 )
         {
            temp = x[j];
            for ( i = 0; i < j; i++ )
               x[i] += temp * a[j*lda+i];

            if ( !unit )
               x[j] *= a[j*(lda+1)];
         }
      }
   else
      for ( j = 0; j < n; j++ )
      {
         if ( x[j*incx] != 0.0 )
         {
            temp = x[j*incx];
            for ( i = 0; i < j; i++ )
               x[i*incx] += temp * a[j*lda+i];

            if ( !unit )
               x[j*incx] *= a[j*(lda+1)];
         }
      }

   /* success */
   return GAN_TRUE;
}

#endif /* #if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK) */
