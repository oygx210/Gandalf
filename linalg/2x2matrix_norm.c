/**
 * File:          $RCSfile: 2x2matrix_norm.c,v $
 * Module:        Projective normalisation of 2x2 matrices (double precision)
 * Part of:       Gandalf Library
 *
 * Revision:      $Revision: 1.12 $
 * Last edited:   $Date: 2003/01/31 18:57:10 $
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

#include <stdio.h>
#include <math.h>
#include <gandalf/linalg/2x2matrix_norm.h>
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

/**
 * \defgroup FixedSizeMatrixNormalise Projective Normalisation of Fixed Size Matrices
 * \{
 */

/**
 * \fn Gan_Bool gan_mat22_normalize ( Gan_Matrix22 *B, int n, double term_threshold, int max_iterations, Gan_SquMatrix22 *Lp )
 * \brief Normalize array of 2x2 matrices to identity inertia moment.
 * \param B array of matrices to normalise
 * \param n number of vectors in array
 * \param term_threshold termination threshold
 * \param max_iterations maximum number of iterations
 * \param Lp pointer to solution for triangular normalising matrix
 * \return #GAN_TRUE on success, or #GAN_FALSE if the algorithm failed.
 *
 * This function applies projective normalization to the array of \a n 2x2
 * matrices \a B. After the normalization, the matrices \a B are transformed
 * by a lower triangular matrix \f$ L \f$, and scaled to unit length, so that
 * the transformed vectors
 * \f[
 *     B'_i = \frac{1}{||B_i L^{-{\top}}||_F}(B_i L^{-{\top}})
 * \f]
 * satisfy the equation
 * \f[
 *     \sum_{i=1\ldots n} ({B'_i}^{\top} B'_i) = \frac{n}{2} I_{2\times 2}
 * \f]
 * where \f$ I_{2\times 2} \f$ is the 2x2 identity matrix.
 *
 * \a term_threshold specifies a threshold on the smallness of an adjustment
 * to \f$ L \f$, below which the algorithm terminates successfully.
 *
 * \a max_iterations specifies the maximum number of iterations to perform.
 * If this is reached without the above threshold being reached, the algorithm
 * terminates with failure, returning #GAN_FALSE.
 *
 * \a Lp is a pointer set to the final solution for the triangular matrix
 * \f$ L \f$. If it is passed as \c NULL then \a Lp is ignored.
 *
 * Upon successful termination, the matrices \a B are transformed to
 * \f$ B'_i \f$ as shown above, and #GAN_TRUE is returned.
 *
 * \sa gan_mat22T_normalize, gan_vec2_normalize(), gan_mat22_normalize().
 */

/**
 * \fn Gan_Bool gan_mat22T_normalize ( Gan_Matrix22 *B, int n, double term_threshold, int max_iterations, Gan_SquMatrix22 *Lp )
 * \brief Normalize array of 2x2 matrices to identity inertia moment.
 * \param B array of matrices to normalise
 * \param n number of vectors in array
 * \param term_threshold termination threshold
 * \param max_iterations maximum number of iterations
 * \param Lp pointer to solution for triangular normalising matrix
 * \return #GAN_TRUE on success, or #GAN_FALSE on failure.
 *
 * This function applies projective normalization to the array of \a n
 * 2x2 matrices \a B. After the normalization, the matrices \a B are
 * transformed by a lower triangular matrix \f$ L \f$, and scaled to unit
 * length, so that the transformed vectors
 * \f[
 *     B'_i = \frac{1}{||L^{-1} B_i||_F}(L^{-1} B_i)
 * \f]
 * satisfy the equation
 * \f[
 *   \sum_{i=1\ldots n} (B'_i {B'_i}^{\top}) = \frac{n}{2} I_{2\times 2}
 * \f]
 * where \f$ I_{2\times 2} \f$ is the 2x2 identity matrix.
 *
 * \a term_threshold specifies a threshold on the smallness of an adjustment
 * to \f$ L \f$, below which the algorithm terminates successfully.
 *
 * \a max_iterations specifies the maximum number of iterations to perform.
 * If this is reached without the above threshold being reached, the algorithm
 * terminates with failure, returning #GAN_FALSE.
 *
 * \a Lp is a pointer set to the final solution for the triangular matrix
 * \f$ L \f$. If it is passed as \c NULL then \a Lp is ignored.
 *
 * Upon successful termination, the matrices \a B are transformed to
 * \f$ B'_i \f$ as shown above, and #GAN_TRUE is returned.
 *
 * \sa gan_mat22_normalize(), gan_vec2_normalize(), gan_mat22_normalize().
 */

#define GAN_MAT_NORMALISE   gan_mat22_normalize
#define GAN_MAT_NORM_FNAME  "gan_mat22_normalize"
#define GAN_MATT_NORMALISE  gan_mat22T_normalize
#define GAN_MATT_NORM_FNAME "gan_mat22T_normalize"
#define GAN_MATTYPE         Gan_Matrix22
#define GAN_SQUMATTYPE      Gan_SquMatrix22
#define GAN_SQUMATTYPEP     Gan_SquMatrix22

#define GAN_MAT_SCALE_S  gan_mat22_scale_s
#define GAN_MAT_DIVIDE_S gan_mat22_divide_s
#define GAN_MAT_FNORM_S  gan_mat22_Fnorm_s
#define GAN_SYMMAT_IDENT_S    gan_symmat22_ident_s
#define GAN_SYMMAT_INVERT_Q   gan_symmat22_invert_q
#define GAN_SYMMAT_ZERO_Q     gan_symmat22_zero_q
#define GAN_SYMMAT_MULTV_Q    gan_symmat22_multv2_q
#define GAN_SYMMAT_DIVIDE_S   gan_symmat22_divide_s
#define GAN_SYMMAT_DIVIDE_I   gan_symmat22_divide_i
#define GAN_SYMMAT_INCREMENT  gan_symmat22_increment
#define GAN_SYMMAT_TRACE_S    gan_symmat22_trace_s
#define GAN_SYMMAT_SUB_Q      gan_symmat22_sub_q
#define GAN_SYMMAT_SUMSQR_Q   gan_symmat22_sumsqr_q
#define GAN_SYMMAT_CHOLESKY_Q gan_symmat22_cholesky_q
#define GAN_SYMMAT_LRMULTM_Q  gan_symmat22_lrmultm22_q
#define GAN_SYMMATP_TRACE_S   gan_symmat22_trace_s
#define GAN_LTMATI_MULTV_S    gan_ltmat22I_multv2_s
#define GAN_MAT_RMULTLIT_S    gan_mat22_rmultl22IT_s
#define GAN_MAT_RMULTLIT_S    gan_mat22_rmultl22IT_s
#define GAN_MAT_SLMULTT_Q     gan_mat22_slmultT_q
#define GAN_MAT_TPOSE_I       gan_mat22_tpose_i 

#include <gandalf/linalg/mat_norm_noc.c>

#undef GAN_MAT_NORMALISE
#undef GAN_MAT_NORM_FNAME
#undef GAN_MATT_NORMALISE
#undef GAN_MATT_NORM_FNAME
#undef GAN_MATTYPE
#undef GAN_SQUMATTYPE
#undef GAN_SQUMATTYPEP
#undef GAN_VEC_SCALE_S
#undef GAN_VEC_DIVIDE_S
#undef GAN_VEC_DOT_S
#undef GAN_VEC_SQRLEN_S
#undef GAN_VEC_OUTER_SYM_Q
#undef GAN_SYMMAT_IDENT_S
#undef GAN_SYMMAT_INVERT_Q
#undef GAN_SYMMAT_ZERO_Q
#undef GAN_SYMMAT_MULTV_Q
#undef GAN_SYMMAT_DIVIDE_S
#undef GAN_SYMMAT_DIVIDE_I
#undef GAN_SYMMAT_INCREMENT
#undef GAN_SYMMAT_TRACE_S
#undef GAN_SYMMAT_SUB_Q
#undef GAN_SYMMAT_SUMSQR_Q
#undef GAN_SYMMAT_CHOLESKY_Q
#undef GAN_SYMMATP_TRACE_S
#undef GAN_LTMATI_MULTV_S
#undef GAN_SYMMAT_LRMULTM_Q
#undef GAN_MAT_RMULTLIT_S
#undef GAN_MAT_RMULTLIT_S
#undef GAN_MAT_SLMULTT_Q
#undef GAN_MAT_TPOSE_I

/**
 * \}
 */

/**
 * \}
 */

/**
 * \}
 */

/**
 * \}
 */
