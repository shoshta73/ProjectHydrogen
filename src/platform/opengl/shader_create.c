#include "shader.h"

#include <glad/glad.h>

#include <stdio.h>

opengl_shader_t
opengl_shader_create(const char* vertex_source, const char* fragment_source)
{
	uint32_t vertex_shader = 0;
	if (vertex_source == NULL)
	{
		vertex_shader = default_vertex_shader();
	}
	else
	{
		vertex_shader = opengl_compile_shader(GL_VERTEX_SHADER, vertex_source);
	}

	uint32_t fragment_shader = opengl_compile_shader(GL_FRAGMENT_SHADER, fragment_source);

	uint32_t ID = glCreateProgram();
	glAttachShader(ID, vertex_shader);
	glAttachShader(ID, fragment_shader);
	glLinkProgram(ID);

	int success = 0;
	char info_log[512];
	glGetProgramiv(ID, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, info_log);
		fprintf(stderr, "Error: Shader program linking failed\n%s\n", info_log);
	}

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	return (opengl_shader_t){ .ID = ID };
}
