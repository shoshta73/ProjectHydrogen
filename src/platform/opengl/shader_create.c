#include "shader.h"

#include <glad/glad.h>

#include <stdio.h>

opengl_shader_t
opengl_shader_create(const char* vertexSource, const char* fragmentSource)
{
	uint32_t vertexShader = default_vertex_shader();
	uint32_t fragmentShader = opengl_compile_shader(GL_FRAGMENT_SHADER, fragmentSource);

	uint32_t ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	int success = 0;
	char infoLog[512];
	glGetProgramiv(ID, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		fprintf(stderr, "Error: Shader program linking failed\n%s\n", infoLog);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return (opengl_shader_t){ .ID = ID };
}
