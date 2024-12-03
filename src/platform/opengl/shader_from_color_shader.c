#include "shader.h"

#include <glad/glad.h>

#include <stdio.h>

opengl_shader_t
opengl_shader_from_color_shader(uint32_t vertex_shader, uint32_t fragment_shader)
{
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
