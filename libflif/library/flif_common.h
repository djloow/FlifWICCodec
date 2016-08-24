#ifndef FLIF_INTERFACE_COMMON_H
#define FLIF_INTERFACE_COMMON_H

/*
FLIF - Free Lossless Image Format

Copyright 2010-2016, Jon Sneyers & Pieter Wuille

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdint.h>
#include <stddef.h>

#ifdef _MSC_VER
#define FLIF_API __cdecl
 #ifdef FLIF_BUILD_DLL
  #define FLIF_DLLIMPORT __declspec(dllexport)
 #elif FLIF_USE_DLL
  #define FLIF_DLLIMPORT __declspec(dllimport)
 #endif
#else
#define FLIF_API
#endif

#ifndef FLIF_DLLIMPORT
#define FLIF_DLLIMPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    typedef struct FLIF_IMAGE FLIF_IMAGE;

    FLIF_DLLIMPORT FLIF_IMAGE* FLIF_API flif_create_image(uint32_t width, uint32_t height, int nb_channels);
    FLIF_DLLIMPORT FLIF_IMAGE* FLIF_API flif_create_image_HDR(uint32_t width, uint32_t height);
    FLIF_DLLIMPORT void FLIF_API flif_destroy_image(FLIF_IMAGE* image);

    FLIF_DLLIMPORT uint32_t FLIF_API flif_image_get_width(FLIF_IMAGE* image);
    FLIF_DLLIMPORT uint32_t FLIF_API flif_image_get_height(FLIF_IMAGE* image);
    FLIF_DLLIMPORT uint8_t  FLIF_API flif_image_get_nb_channels(FLIF_IMAGE* image);
    FLIF_DLLIMPORT uint8_t  FLIF_API flif_image_get_depth(FLIF_IMAGE* image);
    FLIF_DLLIMPORT uint32_t FLIF_API flif_image_get_frame_delay(FLIF_IMAGE* image);
    FLIF_DLLIMPORT void FLIF_API flif_image_set_frame_delay(FLIF_IMAGE* image, uint32_t delay);

	FLIF_DLLIMPORT void FLIF_API flif_write_row_N(FLIF_IMAGE* image, uint32_t row, const void* buffer, size_t buffer_size_bytes);
    FLIF_DLLIMPORT void FLIF_API flif_image_write_row_RGBA8(FLIF_IMAGE* image, uint32_t row, const void* buffer, size_t buffer_size_bytes);
	FLIF_DLLIMPORT void FLIF_API flif_image_read_row_N(FLIF_IMAGE* image, uint32_t row, void* buffer, size_t buffer_size_bytes);
    FLIF_DLLIMPORT void FLIF_API flif_image_read_row_RGBA8(FLIF_IMAGE* image, uint32_t row, void* buffer, size_t buffer_size_bytes);

    FLIF_DLLIMPORT void FLIF_API flif_image_write_row_RGBA16(FLIF_IMAGE* image, uint32_t row, const void* buffer, size_t buffer_size_bytes);
    FLIF_DLLIMPORT void FLIF_API flif_image_read_row_RGBA16(FLIF_IMAGE* image, uint32_t row, void* buffer, size_t buffer_size_bytes);

    FLIF_DLLIMPORT void FLIF_API flif_free_memory(void* buffer);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FLIF_INTERFACE_COMMON_H
