#include "color.h"

#include <glad/glad.h>

#include <stdio.h>

uint32_t
opengl_color_to_vertex_shader(opengl_color_t* color)
{
	char _buffer[256] = { 0 };
	char* buffer = _buffer;

	if (color == NULL)
	{
		// TODO: Handle this error -> Return an error code, or handle it as needed
		fprintf(stderr, "Error: Color was NULL!\n");
		return 0;
	}

	size_t len = snprintf(buffer,
												sizeof(_buffer),
												"#version 330 core\nout vec4 FragColor;\nvoid main() {\nFragColor = vec4(%f, %f, %f, %f);\n}",
												color->r / 255.0f,
												color->g / 255.0f,
												color->b / 255.0f,
												color->a / 255.0f);

	if (len >= sizeof(_buffer))
	{
		// TODO: Handle this error -> Return an error code, or handle it as needed
		fprintf(stderr, "Error: Shader source was too large to fit in the buffer!\n");
		return 0;
	}

	return opengl_compile_shader(GL_FRAGMENT_SHADER, buffer);
}
