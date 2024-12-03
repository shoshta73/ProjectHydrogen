#include "shader.h"

#include <glad/glad.h>

#define DEFAULT_VERTEX_SHADER_SOURCE                                                                                   \
	"#version 330 core\nlayout (location = 0) in vec3 aPos;\nvoid main() {\ngl_Position = vec4(aPos, 1.0);\n}"

uint32_t
default_vertex_shader()
{
	return opengl_compile_shader(GL_VERTEX_SHADER, DEFAULT_VERTEX_SHADER_SOURCE);
}
