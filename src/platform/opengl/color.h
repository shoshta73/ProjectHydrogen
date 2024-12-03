#include <stdint.h>

#ifndef __STRING
#define __STRING(x) #x
#endif

#ifndef __STRINGIFY
#define __STRINGIFY(x) __STRING(x)
#endif

#pragma once

#ifndef PROJECT_HYDROGEN_PLATFORM_OPENGL_COLOR_H
#define PROJECT_HYDROGEN_PLATFORM_OPENGL_COLOR_H

#ifdef __cplusplus
extern "C"
{
#endif
	struct opengl_color
	{
		uint32_t r;
		uint32_t g;
		uint32_t b;
		uint32_t a;
	};

	typedef struct opengl_color opengl_color_t;

	uint32_t opengl_color_to_vertex_shader(opengl_color_t* color);

#ifdef __cplusplus
}
#endif

#endif // PROJECT_HYDROGEN_PLATFORM_OPENGL_COLOR_H
