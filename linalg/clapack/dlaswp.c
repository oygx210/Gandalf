/**************************************************************************
*
* File:          $RCSfile: dlaswp.c,v $
* Module:        CLAPACK function
* Part of:       Gandalf Library
*
* Revision:      $Revision: 1.2 $
* Last edited:   $Date: 2005/02/25 09:30:24 $
* Author:        $Author: pm $
* Copyright:     Modifications (c) 2000 Imagineer Software Limited
*
* Notes:         
* Private func:  
* History:       Modified from original CLAPACK source code 
*
**************************************************************************/

#include <math.h>
#include <gandalf/linalg/clapack/dlaswp.h>
#include <gandalf/linalg/cblas.h>
#include <gandalf/common/misc_defs.h>
#include <gandalf/common/array.h>
#include <gandalf/common/compare.h>

/* only define this function locally if there is no LAPACK installed */
#if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK)

/* modified from CLAPACK source */
Gan_Bool
 gan_dlaswp ( long n, double *a, long lda, long k1, long k2,
              long *ipiv, long incx )
{
   long i, ip, ix;

#define IPIV(I) ipiv[(I)]

#define A(I,J) a[(I) + (J)*(lda)]
   if (incx == 0)	return GAN_TRUE;

   if (incx > 0) ix = k1;
   else ix = -k2*incx;

   if (incx == 1)
      for (i = k1; i <= k2; ++i)
      {
         ip = IPIV(i);
         if (ip != i)
            gan_dswap ( n, &A(i,0), lda, &A(ip,0), lda );
      }
   else if (incx > 1)
      for (i = k1; i <= k2; ++i)
      {
         ip = IPIV(ix);
         if (ip != i)
            gan_dswap ( n, &A(i,0), lda, &A(ip,0), lda );

         ix += incx;
      }
   else if (incx < 0)
      for (i = k2; i >= k1; --i)
      {
         ip = IPIV(ix);
         if (ip != i)
            gan_dswap ( n, &A(i,0), lda, &A(ip,0), lda );

         ix += incx;
      }

   /* success */
   return GAN_TRUE;
}

#endif /* #if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK) */

