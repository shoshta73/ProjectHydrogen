#include "shader.h"

#include <glad/glad.h>

void
opengl_shader_destroy(opengl_shader_t* shader)
{
	glDeleteProgram(shader->ID);
}

void
opengl_shader_delete(opengl_shader_t* shader)
{
	opengl_shader_destroy(shader);
};
