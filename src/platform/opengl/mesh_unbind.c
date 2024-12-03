#include "mesh.h"

#include <glad/glad.h>

void
opengl_mesh_unbind(opengl_mesh_t* mesh)
{
	glBindVertexArray(0);
}
