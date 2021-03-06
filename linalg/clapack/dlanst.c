/**************************************************************************
*
* File:          $RCSfile: dlanst.c,v $
* Module:        CLAPACK function
* Part of:       Gandalf Library
*
* Revision:      $Revision: 1.2 $
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
#include <gandalf/linalg/clapack/dlanst.h>
#include <gandalf/linalg/clapack/dlassq.h>
#include <gandalf/common/compare.h>

/* only define this function locally if there is no LAPACK installed */
#if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK)

/* modified from CLAPACK source */
double gan_dlanst(Gan_LapackNormType norm, long n, double *d, double *e)
{
   double ret_val, d__3, d__4, d__5;
   long i__;
   double scale;
   double anorm=0.0;
   double sum;

   /* Function Body */
   if (n <= 0) {
      anorm = 0.;
   }
   else if (norm == GAN_NORMTYPE_MAXABSVAL)
   {
      /*        Find max(abs(A(i,j))). */
      anorm = fabs(d[n-1]);
      for (i__ = 0; i__ < n-1; ++i__)
      {
         /* Computing MAX */
         anorm = gan_max2(anorm, fabs(d[i__]));

         /* Computing MAX */
         anorm = gan_max2_d(anorm, fabs(e[i__]));
      }
   }
   else if (norm == GAN_NORMTYPE_ONE || norm == GAN_NORMTYPE_INFINITY)
   {
      /*        Find norm1(A). */
      if (n == 1)
         anorm = fabs(d[0]);
      else
      {
         /* Computing MAX */
         d__3 = abs(d[0]) + abs(e[0]);
         d__4 = fabs(e[n-2]) + fabs(d[n-1]);
         anorm = gan_max2(d__3,d__4);
         for (i__ = 1; i__ < n-1; ++i__)
         {
            /* Computing MAX */
            d__4 = anorm;
            d__5 = fabs(d[i__]) + fabs(e[i__]) + fabs(e[i__-1]);
            anorm = gan_max2(d__4,d__5);
         }
      }
   }
   else if (norm == GAN_NORMTYPE_FROBENIUS)
   {
      /*        Find normF(A). */
      scale = 0.0;
      sum = 1.0;
      if (n > 1)
      {
         gan_dlassq(n-1, e, 1, &scale, &sum);
         sum *= 2;
      }

      gan_dlassq(n, d, 1, &scale, &sum);
      anorm = scale * sqrt(sum);
   }

   ret_val = anorm;
   return ret_val;
}

#endif /* #if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK) */


