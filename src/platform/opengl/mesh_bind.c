#include "mesh.h"

#include <glad/glad.h>

void
opengl_mesh_bind(opengl_mesh_t* mesh)
{
	glBindVertexArray(mesh->VAO);
}
