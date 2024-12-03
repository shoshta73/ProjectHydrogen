#include "shader.h"

#include <glad/glad.h>

#include <stdio.h>
#include <stdlib.h>

uint32_t
opengl_compile_shader(uint32_t type, const char* source)
{
	uint32_t shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	int success = 0;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		fprintf(stderr, "Error: Shader compilation failed\n%s\n", infoLog);
	}

	return shader;
}
