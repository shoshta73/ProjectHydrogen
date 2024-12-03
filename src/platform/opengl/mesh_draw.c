#include "mesh.h"

#include <glad/glad.h>

void
opengl_mesh_draw(opengl_mesh_t* mesh)
{
	opengl_mesh_bind(mesh);
	glDrawElements(GL_TRIANGLES, mesh->index_count, GL_UNSIGNED_INT, 0);
	opengl_mesh_unbind(mesh);
}
