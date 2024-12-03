/**
 * ProjecyHydrogen
 * Copyright (c) 2024 Borna Šoštarić
 * Licensed under the MIT License
 *
 * File: shader.h (src/platform/opengl/shader.h)
 *
 * Revision: 1
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
 *
 * Revision History: (date - author - revision - short - description)
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

	opengl_shader_t opengl_shader_create(const char* vertexSource, const char* fragmentSource);

	void opengl_shader_destroy(opengl_shader_t* shader);

	void opengl_shader_delete(opengl_shader_t* shader);

	uint32_t opengl_compile_shader(uint32_t type, const char* source);

	void opengl_shader_use(opengl_shader_t* shader);

#ifdef __cplusplus
}
#endif

#endif // PROJECT_HYDROGEN_PLATFORM_OPENGL_SHADER_H
