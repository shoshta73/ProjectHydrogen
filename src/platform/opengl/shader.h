/**
 * ProjecyHydrogen
 * Copyright (c) 2024 Borna Šoštarić
 * Licensed under the MIT License
 *
 * File: shader.h (src/platform/opengl/shader.h)
 *
 * Revision: 2
 * Date: 2024-12-03
 *
 * Description: OpenGL shader abstraction
 *
 * 	structs: (name - short description)
 * 	  opengl_shader - OpenGL shader
 *
 * types: (name - short description - notes)
 *   opengl_shader_t - OpenGL shader (alias of opengl_shader)
 *
 * functions: (name - short description)
 *   opengl_shader_create - create shader
 *   opengl_shader_destroy - destroy shader (frees memory)
 *   opengl_shader_delete - delete shader (frees memory) (alias of destroy)
 *   opengl_shader_use - use shader
 *   default_vertex_shader - get default vertex shader
 *
 * Revision History: (date - author - revision - short - description)
 *   2024-12-03 - Borna Šoštarić - 2 - Color support:
 *   2024-12-03 - Borna Šoštarić - 2 - Addition:
 *     Added default_vertex_shader()
 *   2024-12-03 - Borna Šoštarić - 1 - Created:
 * 	   Created Shader abstraction,
 *     Implemented shader creation,
 *     Implemented shader destruction,
 *     Implemented shader usage
 */

#include <stdint.h>

#pragma once

#ifndef PROJECT_HYDROGEN_PLATFORM_OPENGL_SHADER_H
#define PROJECT_HYDROGEN_PLATFORM_OPENGL_SHADER_H

#ifdef __cplusplus
extern "C"
{
#endif

	struct opengl_shader
	{
		uint32_t ID;
	};

	typedef struct opengl_shader opengl_shader_t;

	opengl_shader_t opengl_shader_create(const char* vertex_source, const char* fragment_source);
	opengl_shader_t opengl_shader_from_color_shader(uint32_t vertex_shader, uint32_t fragment_shader);

	void opengl_shader_destroy(opengl_shader_t* shader);

	void opengl_shader_delete(opengl_shader_t* shader);

	uint32_t opengl_compile_shader(uint32_t type, const char* source);

	void opengl_shader_use(opengl_shader_t* shader);

	uint32_t default_vertex_shader();

#ifdef __cplusplus
}
#endif

#endif // PROJECT_HYDROGEN_PLATFORM_OPENGL_SHADER_H
