#include "shader.h"

#include <glad/glad.h>

void
opengl_shader_use(opengl_shader_t* shader)
{
	glUseProgram(shader->ID);
}
