#include "mesh.h"

#include <glad/glad.h>

opengl_mesh_t
opengl_mesh_create(const float* vertices, uint32_t vertex_count, const uint32_t* indices, uint32_t index_count)
{
	opengl_mesh_t mesh = { 0 };
	mesh.vertex_count = vertex_count;
	mesh.index_count = index_count;

	uint32_t VAO = 0, VBO = 0, EBO = 0;

	// Generate and bind VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	mesh.VAO = VAO;

	// Generate and bind VBO
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertex_count, vertices, GL_STATIC_DRAW);
	mesh.VBO = VBO;

	// Generate and bind EBO
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * index_count, indices, GL_STATIC_DRAW);
	mesh.EBO = EBO;

	// Specify the vertex attribute layout
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Unbind VAO to prevent accidental modification
	glBindVertexArray(0);
	return mesh;
}
