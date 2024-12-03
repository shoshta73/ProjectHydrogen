/**
 * ProjecyHydrogen
 * Copyright (c) 2024 Borna Šoštarić
 * Licensed under the MIT License
 *
 * File: shader.h (src/platform/opengl/mesh.h)
 *
 * Revision: 1
 * Date: 2024-12-03
 *
 * Description: OpenGL mesh abstraction
 *
 * structs: (name - short description)
 *   opengl_mehs - OpenGL mesh
 *
 * tpyes: (name - short description - notes)
 *   opengl_mesh_t - OpenGL mesh (alias of opengl_mesh)
 *
 * functions: (name - short description)
 *   opengl_mesh_create - create mesh
 *   opengl_mesh_destroy - destroy mesh (frees memory)
 *   opengl_mesh_delete - delete mesh (frees memory) (alias of destroy)
 *   opengl_mesh_draw - draw mesh
 *   opengl_mesh_bind - bind mesh
 *   opengl_mesh_unbind - unbind mesh
 *
 * Revision History: (date - author - revision - short - description)
 *   2024-12-03 - Borna Šoštarić - 1 - Created:
 * 	   Created Mesh abstraction,
 *     Implemented mesh creation,
 *     Implemented mesh destruction,
 *     Implemented mesh drawing,
 *     Implemented mesh binding,
 *     Implemented mesh unbinding
 */

#include <stdint.h>

#pragma once

#ifndef PROJECT_HYDROGEN_PLATFORM_OPENGL_MESH_H
#define PROJECT_HYDROGEN_PLATFORM_OPENGL_MESH_H

#ifdef __cplusplus
extern "C"
{
#endif

	struct opengl_mesh
	{
		uint32_t VAO;
		uint32_t VBO;
		uint32_t EBO;
		uint32_t index_count;
		uint32_t vertex_count;
	};

	typedef struct opengl_mesh opengl_mesh_t;

	opengl_mesh_t opengl_mesh_create(const float* vertices,
																	 uint32_t vertex_count,
																	 const uint32_t* indices,
																	 uint32_t index_count);

	void opengl_mesh_destroy(opengl_mesh_t* mesh);

	void opengl_mesh_delete(opengl_mesh_t* mesh);

	void opengl_mesh_draw(opengl_mesh_t* mesh);

	void opengl_mesh_bind(opengl_mesh_t* mesh);

	void opengl_mesh_unbind(opengl_mesh_t* mesh);

#ifdef __cplusplus
}
#endif

#endif
