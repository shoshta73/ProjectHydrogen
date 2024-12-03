#include "mesh.h"

#include <glad/glad.h>

void
opengl_mesh_destroy(opengl_mesh_t* mesh)
{
	glDeleteBuffers(1, &mesh->VBO);
	glDeleteBuffers(1, &mesh->EBO);
	glDeleteVertexArrays(1, &mesh->VAO);
}

void
opengl_mesh_delete(opengl_mesh_t* mesh)
{
	opengl_mesh_destroy(mesh);
}
