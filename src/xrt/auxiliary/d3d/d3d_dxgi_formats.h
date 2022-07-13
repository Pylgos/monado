// Copyright 2020-2022, Collabora, Ltd.
// SPDX-License-Identifier: BSL-1.0
/*!
 * @file
 * @brief Format conversion for DXGI/D3D.
 * @author Ryan Pavlik <ryan.pavlik@collabora.com>
 * @ingroup aux_d3d
 */

#pragma once

#include "xrt/xrt_windows.h"
#include "xrt/xrt_vulkan_includes.h"

#include <dxgiformat.h>


#ifdef __cplusplus
extern "C" {
#endif

static inline DXGI_FORMAT
d3d_vk_format_to_dxgi(int64_t format)
{
	switch (format) {
	case VK_FORMAT_B8G8R8A8_SRGB: return DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
	case VK_FORMAT_B8G8R8A8_UNORM: return DXGI_FORMAT_B8G8R8A8_UNORM;
	case VK_FORMAT_D16_UNORM: return DXGI_FORMAT_D16_UNORM;
	case VK_FORMAT_D24_UNORM_S8_UINT: return DXGI_FORMAT_D24_UNORM_S8_UINT;
	case VK_FORMAT_D32_SFLOAT_S8_UINT: return DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
	case VK_FORMAT_D32_SFLOAT: return DXGI_FORMAT_D32_FLOAT;
	// case VK_FORMAT_R16G16B16_SFLOAT: return DXGI_FORMAT_R16G16B16A16_FLOAT; /// @todo OK to just add A?
	// case VK_FORMAT_R16G16B16_UNORM: return DXGI_FORMAT_R16G16B16A16_UNORM;  /// @todo OK to just add A?
	case VK_FORMAT_R16G16B16A16_SFLOAT: return DXGI_FORMAT_R16G16B16A16_FLOAT;
	case VK_FORMAT_R16G16B16A16_UNORM: return DXGI_FORMAT_R16G16B16A16_UNORM;
	case VK_FORMAT_R8G8B8A8_SRGB: return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
	case VK_FORMAT_R8G8B8A8_UNORM: return DXGI_FORMAT_R8G8B8A8_UNORM; // Should not be used, colour precision.

	case VK_FORMAT_X8_D24_UNORM_PACK32: /// @todo DXGI_FORMAT_D24_UNORM_S8_UINT ?
		return (DXGI_FORMAT)0;
	case VK_FORMAT_A2B10G10R10_UNORM_PACK32: /// @todo DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM ?
		return (DXGI_FORMAT)0;

	default: return (DXGI_FORMAT)0;
	}
}

static inline DXGI_FORMAT
d3d_dxgi_format_to_typeless_dxgi(DXGI_FORMAT format)
{
	switch (format) {
	case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB: //
	case DXGI_FORMAT_B8G8R8A8_UNORM:      //
		return DXGI_FORMAT_B8G8R8A8_TYPELESS;

	case DXGI_FORMAT_D16_UNORM: //
		return DXGI_FORMAT_R16_TYPELESS;

	case DXGI_FORMAT_D32_FLOAT: //
		return DXGI_FORMAT_R32_TYPELESS;

	case DXGI_FORMAT_D24_UNORM_S8_UINT: //
		return DXGI_FORMAT_R24G8_TYPELESS;

	case DXGI_FORMAT_D32_FLOAT_S8X24_UINT: //
		return DXGI_FORMAT_R32G8X24_TYPELESS;

	case DXGI_FORMAT_R16G16B16A16_FLOAT: //
	case DXGI_FORMAT_R16G16B16A16_UNORM: //
		return DXGI_FORMAT_R16G16B16A16_TYPELESS;

	case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
	case DXGI_FORMAT_R8G8B8A8_UNORM: //
		return DXGI_FORMAT_R8G8B8A8_TYPELESS;

	default: return format;
	}
}

static inline int64_t
d3d_dxgi_format_to_vk(DXGI_FORMAT format)
{
	switch (format) {
	case DXGI_FORMAT_R8G8B8A8_UNORM: return VK_FORMAT_R8G8B8A8_UNORM; // Should not be used, colour precision.
	case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB: return VK_FORMAT_R8G8B8A8_SRGB;
	case DXGI_FORMAT_B8G8R8A8_UNORM: return VK_FORMAT_B8G8R8A8_UNORM;
	case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB: return VK_FORMAT_B8G8R8A8_SRGB;
	case DXGI_FORMAT_R16G16B16A16_FLOAT: return VK_FORMAT_R16G16B16A16_SFLOAT;
	case DXGI_FORMAT_R16G16B16A16_UNORM: return VK_FORMAT_R16G16B16A16_UNORM;
	case DXGI_FORMAT_R16G16B16A16_SNORM: return VK_FORMAT_R16G16B16A16_SNORM;
	case DXGI_FORMAT_D16_UNORM: return VK_FORMAT_D16_UNORM;
	case DXGI_FORMAT_D32_FLOAT: return VK_FORMAT_D32_SFLOAT;
	case DXGI_FORMAT_D24_UNORM_S8_UINT: return VK_FORMAT_D24_UNORM_S8_UINT;
	case DXGI_FORMAT_D32_FLOAT_S8X24_UINT: return VK_FORMAT_D32_SFLOAT_S8_UINT;
	default: return 0;
	}
}

static inline UINT
d3d_convert_usage_bits_to_bind_flags(enum xrt_swapchain_usage_bits xsub)
{
	int ret = 0;
	if ((xsub & XRT_SWAPCHAIN_USAGE_COLOR) != 0) {
		ret |= D3D11_BIND_RENDER_TARGET;
	}
	if ((xsub & XRT_SWAPCHAIN_USAGE_DEPTH_STENCIL) != 0) {
		ret |= D3D11_BIND_DEPTH_STENCIL;
	}
	if ((xsub & XRT_SWAPCHAIN_USAGE_UNORDERED_ACCESS) != 0) {
		ret |= D3D11_BIND_UNORDERED_ACCESS;
	}
	if ((xsub & XRT_SWAPCHAIN_USAGE_SAMPLED) != 0) {
		ret |= D3D11_BIND_SHADER_RESOURCE;
	}
	return ret;
}

#ifdef __cplusplus
}
#endif
