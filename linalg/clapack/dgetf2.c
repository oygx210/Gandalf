/**************************************************************************
*
* File:          $RCSfile: dgetf2.c,v $
* Module:        CLAPACK function
* Part of:       Gandalf Library
*
* Revision:      $Revision: 1.5 $
* Last edited:   $Date: 2005/02/25 09:30:23 $
* Author:        $Author: pm $
* Copyright:     Modifications (c) 2000 Imagineer Software Limited
*
* Notes:         
* Private func:  
* History:       Modified from original CLAPACK source code 
*
**************************************************************************/

#include <math.h>
#include <gandalf/linalg/clapack/dgetf2.h>
#include <gandalf/linalg/cblas.h>
#include <gandalf/common/misc_defs.h>
#include <gandalf/common/array.h>
#include <gandalf/common/compare.h>

/* only define this function locally if there is no LAPACK installed */
#if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK)

/* modified from CLAPACK source */
Gan_Bool
 gan_dgetf2 ( long m, long n, double *a, long lda, long *ipiv, long *info )
{
   long minmn = gan_min2_l(m,n), j, jp;

   /* check arguments */
   if ( m < 0 )
   {
      *info = -1;
      return GAN_FALSE;
   }

   if ( n < 0 )
   {
      *info = -2;
      return GAN_FALSE;
   }

   if ( lda < gan_max2_l(1,m) )
   {
      *info = -4;
      return GAN_FALSE;
   }

   /* return immediately if matrix is zero size */
   *info = 0;
   if ( m == 0 || n == 0 ) return GAN_TRUE;

   for ( j = 0; j < minmn; j++ )
   {
      /* locate pivot */
      jp = j + gan_idamax(m-j, &a[j*(lda+1)], 1);
      ipiv[j] = jp;
      if ( a[j*lda+jp] == 0.0 )
      {
         *info = j;
         return GAN_FALSE;
      }

      /* swap columns 0 and n-1 */
      if ( jp != j )
         gan_dswap ( n, &a[j], lda, &a[jp], lda );

      if ( j < m-1 )
         gan_dscal ( m-j-1, 1.0/a[j*(lda+1)], &a[j*lda+j+1], 1 );

      if ( j < minmn )
         gan_dger ( m-j-1, n-j-1, -1.0, &a[j*lda+j+1], 1,
                    &a[(j+1)*lda+j], lda, &a[(j+1)*(lda+1)], lda );
   }

   /* success */
   return GAN_TRUE;
}

#endif /* #if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK) */
