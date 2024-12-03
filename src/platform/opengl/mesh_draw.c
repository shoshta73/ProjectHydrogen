#include "mesh.h"

#include <glad/glad.h>

void
opengl_mesh_draw(opengl_mesh_t* mesh)
{
	// Bind VAO
	glBindVertexArray(mesh->VAO);
	glDrawElements(GL_TRIANGLES, mesh->index_count, GL_UNSIGNED_INT, 0);
	// Unbind VAO
	glBindVertexArray(0);
}
