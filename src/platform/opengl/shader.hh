#include <glad/glad.h>

#pragma once

#ifndef PROJECT_HYDROGEN_PLATFORM_OPENGL_SHADER_HH
#define PROJECT_HYDROGEN_PLATFORM_OPENGL_SHADER_HH

namespace ProjectHydrogen
{

class Shader
{
public:
	Shader(const char* vertexSource, const char* fragmentSource);
	~Shader() { glDeleteProgram(ID); }
	void Use() const { glUseProgram(ID); }

private:
	unsigned int ID;
	static unsigned int compileShader(unsigned int type, const char* source);
};

} // namespace ProjectHydrogen

#endif // PROJECT_HYDROGEN_PLATFORM_OPENGL_SHADER_HH
