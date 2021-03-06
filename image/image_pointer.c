/**
 * File:          $RCSfile: image_pointer.c,v $
 * Module:        Images of pointers
 * Part of:       Gandalf Library
 *
 * Revision:      $Revision: 1.17 $
 * Last edited:   $Date: 2004/03/17 16:14:20 $
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

#include <gandalf/image/image_pointer.h>

#define GAN_PIXEL void *
#define GAN_PIXEL_FORMAT grey-level
#define GAN_PIXEL_TYPE void *
#define GAN_PIXTYPE GAN_POINTER
#define GAN_IMTYPE p
#define GAN_IMAGE_FORM_GEN gan_image_form_gen_p
#define GAN_IMAGE_SET_GEN gan_image_set_gen_p
#define GAN_IMAGE_ALLOC gan_image_alloc_p
#define GAN_IMAGE_ALLOC_DATA gan_image_alloc_data_p
#define GAN_IMAGE_FORM gan_image_form_p
#define GAN_IMAGE_FORM_DATA gan_image_form_data_p
#define GAN_IMAGE_SET gan_image_set_p
#define GAN_IMAGE_SET_PIX gan_image_set_pix_p
#define GAN_IMAGE_GET_PIX gan_image_get_pix_p
#define GAN_IMAGE_GET_PIXPTR gan_image_get_pixptr_p
#define GAN_IMAGE_GET_PIXARR gan_image_get_pixarr_p
#define GAN_IMAGE_FILL_CONST gan_image_fill_const_p
#define GAN_IMAGE_GET_ACTIVE_SUBWINDOW gan_image_get_active_subwindow_p
#define GAN_IMAGE_MASK_WINDOW gan_image_mask_window_p
#define GAN_IMAGE_CLEAR_WINDOW gan_image_clear_window_p
#define GAN_IMAGE_PIXEL_ZERO_VAL NULL
#define GAN_FILL_ARRAY gan_fill_array_p
#define GAN_COPY_ARRAY gan_copy_array_p

#include <gandalf/image/image_grey_noc.c>

#undef GAN_PIXEL
#undef GAN_PIXEL_FORMAT
#undef GAN_PIXEL_TYPE
#undef GAN_PIXTYPE
#undef GAN_IMTYPE
#undef GAN_IMAGE_FORM_GEN
#undef GAN_IMAGE_SET_GEN
#undef GAN_IMAGE_ALLOC
#undef GAN_IMAGE_ALLOC_DATA
#undef GAN_IMAGE_FORM
#undef GAN_IMAGE_FORM_DATA
#undef GAN_IMAGE_SET
#undef GAN_IMAGE_SET_PIX
#undef GAN_IMAGE_GET_PIX
#undef GAN_IMAGE_GET_PIXPTR
#undef GAN_IMAGE_GET_PIXARR
#undef GAN_IMAGE_FILL_CONST
#undef GAN_IMAGE_GET_ACTIVE_SUBWINDOW
#undef GAN_IMAGE_MASK_WINDOW
#undef GAN_IMAGE_CLEAR_WINDOW
#undef GAN_IMAGE_PIXEL_ZERO_VAL
#undef GAN_FILL_ARRAY
#undef GAN_COPY_ARRAY
