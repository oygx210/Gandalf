/**
 * File:          $RCSfile: image_rgb_uint.c,v $
 * Module:        RGB colour unsigned integer images
 * Part of:       Gandalf Library
 *
 * Revision:      $Revision: 1.17 $
 * Last edited:   $Date: 2004/11/20 00:53:11 $
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

#include <gandalf/image/image_rgb_uint.h>
#include <gandalf/image/image_bit.h>

#define GAN_PIXEL struct Gan_RGBPixel_ui
#define GAN_PIXEL_FORMAT RGB colour
#define GAN_PIXEL_TYPE unsigned int
#define GAN_PIXFMT GAN_RGB_COLOUR_IMAGE
#define GAN_PIXTYPE GAN_UINT
#define GAN_IMFMT rgb
#define GAN_IMTYPE ui
#define GAN_PIX_FIELD1 R
#define GAN_PIX_FIELD2 G
#define GAN_PIX_FIELD3 B
#define GAN_IMAGE_FORM_GEN gan_image_form_gen_rgb_ui
#define GAN_IMAGE_SET_GEN gan_image_set_gen_rgb_ui
#define GAN_IMAGE_ALLOC gan_image_alloc_rgb_ui
#define GAN_IMAGE_ALLOC_DATA gan_image_alloc_data_rgb_ui
#define GAN_IMAGE_FORM gan_image_form_rgb_ui
#define GAN_IMAGE_FORM_DATA gan_image_form_data_rgb_ui
#define GAN_IMAGE_SET gan_image_set_rgb_ui
#define GAN_IMAGE_SET_PIX gan_image_set_pix_rgb_ui
#define GAN_IMAGE_GET_PIX gan_image_get_pix_rgb_ui
#define GAN_IMAGE_GET_PIXPTR gan_image_get_pixptr_rgb_ui
#define GAN_IMAGE_GET_PIXARR gan_image_get_pixarr_rgb_ui
#define GAN_IMAGE_FILL_CONST gan_image_fill_const_rgb_ui
#define GAN_IMAGE_GET_ACTIVE_SUBWINDOW gan_image_get_active_subwindow_rgb_ui
#define GAN_IMAGE_MASK_WINDOW gan_image_mask_window_rgb_ui
#define GAN_IMAGE_CLEAR_WINDOW gan_image_clear_window_rgb_ui
#define GAN_IMAGE_GET_MINIMUM_PIXEL gan_image_get_minimum_pixel_rgb_ui
#define GAN_IMAGE_GET_MAXIMUM_PIXEL gan_image_get_maximum_pixel_rgb_ui
#define GAN_IMAGE_PIXEL_MIN_VAL 0
#define GAN_IMAGE_PIXEL_MAX_VAL UINT_MAX
#define GAN_IMAGE_PIXEL_ZERO_VAL 0
#define GAN_FILL_ARRAY gan_fill_array_ui
#define GAN_COPY_ARRAY gan_copy_array_ui

#include <gandalf/image/image_colour_noc.c>

#undef GAN_PIXEL
#undef GAN_PIXEL_FORMAT
#undef GAN_PIXEL_TYPE
#undef GAN_PIXFMT
#undef GAN_PIXTYPE
#undef GAN_IMFMT
#undef GAN_IMTYPE
#undef GAN_PIX_FIELD1
#undef GAN_PIX_FIELD2
#undef GAN_PIX_FIELD3
#undef GAN_PIX_FIELD4
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
#undef GAN_IMAGE_GET_MINIMUM_PIXEL
#undef GAN_IMAGE_GET_MAXIMUM_PIXEL
#undef GAN_IMAGE_PIXEL_MIN_VAL
#undef GAN_IMAGE_PIXEL_MAX_VAL
#undef GAN_IMAGE_PIXEL_ZERO_VAL
#undef GAN_FILL_ARRAY
#undef GAN_COPY_ARRAY
