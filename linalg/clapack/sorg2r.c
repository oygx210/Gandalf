/**************************************************************************
*
* File:          $RCSfile: sorg2r.c,v $
* Module:        CLAPACK function
* Part of:       Gandalf Library
*
* Revision:      $Revision: 1.7 $
* Last edited:   $Date: 2005/02/25 09:30:25 $
* Author:        $Author: pm $
* Copyright:     Modifications (c) 2000 Imagineer Software Limited
*
* Notes:         
* Private func:  
* History:       Modified from original CLAPACK source code 
*
**************************************************************************/

#include <math.h>
#include <gandalf/linalg/clapack/sorg2r.h>
#include <gandalf/linalg/clapack/slarf.h>
#include <gandalf/linalg/cblas.h>
#include <gandalf/common/misc_defs.h>
#include <gandalf/common/array.h>
#include <gandalf/common/compare.h>

/* only define this function locally if there is no LAPACK installed */
#if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK)

/* modified from CLAPACK source */
Gan_Bool
 gan_sorg2r ( long m, long n, long k, float *a, long lda,
              float *tau, float *work, long *info )
{
   long i, j, l;

   *info = 0;
   if ( m < 0 )        *info = -1;
   else if ( n < 0 || n > m ) *info = -2;
   else if ( k < 0 || k > n ) *info = -3;
   else if ( lda < gan_max2(1,m)) *info = -5;
   if (*info != 0)
      return GAN_FALSE;

   /*     Quick return if possible */
   if ( n == 0) return GAN_FALSE;

   /*     Initialise columns k+1:n to columns of the unit matrix */
   for ( j = k; j < n; j++ )
   {
      for ( l = 0; l < m; l++ )
         a[j*lda+l] = 0.0F;

      a[j*(lda+1)] = 1.0F;
   }

   for ( i = k-1; i >= 0; i-- )
   {
      /*        Apply H(i) to A(i:m,i:n) from the left */
      if (i < n-1)
      {
         a[i*(lda+1)] = 1.0F;
         gan_slarf ( GAN_LEFTMULT, m-i, n-i-1, &a[i*(lda+1)], 1, tau[i],
                     &a[(i+1)*lda+i], lda, work );
      }

      if ( i < m-1 )
         gan_sscal ( m-i-1, -tau[i], &a[i*lda+i+1], 1 );

      a[i*(lda+1)] = 1.0F-tau[i];

      /*        Set A(1:i-1,i) to zero */
      for ( l = 0; l < i; l++ )
         a[i*lda+l] = 0.0F;
   }

   /* success */
   return GAN_TRUE;
}

#endif /* #if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK) */
