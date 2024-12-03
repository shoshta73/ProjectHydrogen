#include <vector>

#pragma once

#ifndef PROJECT_HYDROGEN_PLATFORM_OPENGL_MESH_HH
#define PROJECT_HYDROGEN_PLATFORM_OPENGL_MESH_HH

namespace ProjectHydrogen
{
class Mesh
{
public:
	Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
	~Mesh();

	void Draw() const;

private:
	unsigned int VAO, VBO, EBO;
	unsigned int indexCount;

	void bind() const;
	void unbind() const;
};
} // namespace ProjectHydrogen

#endif // PROJECT_HYDROGEN_PLATFORM_OPENGL_MESH_HH
