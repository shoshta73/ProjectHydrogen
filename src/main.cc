#include <platform/opengl/mesh.hh>
#include <platform/opengl/shader.hh>
#include <platform/platform.hh>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos, 1.0);
    }
)";

const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(1.0, 0.0, 0.0, 1.0); // Red color
    }
)";

const char* fragmentShaderSource2 = R"(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(1.0, 1.0, 0.0, 1.0); // Yellow color
    }
)";

void
framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int
main()
{
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Square", nullptr, nullptr);
	if (!window)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	std::vector<float> vertices = {
		// Positions
		-0.05f, -0.05f, 0.0f, // Bottom-left
		0.05f,  -0.05f, 0.0f, // Bottom-right
		0.05f,  0.05f,  0.0f, // Top-right
		-0.05f, 0.05f,  0.0f  // Top-left
	};

	std::vector<float> vertices2 = {
		// Positions
		0.45f, 0.45f, 0.0f, // Bottom-left
		0.55f, 0.45f, 0.0f, // Bottom-right
		0.55f, 0.55f, 0.0f, // Top-right
		0.45f, 0.55f, 0.0f  // Top-left
	};

	std::vector<unsigned int> indices = {
		0, 1, 2, // First triangle
		2, 3, 0  // Second triangle
	};

	ProjectHydrogen::Mesh mesh(vertices, indices);
	ProjectHydrogen::Mesh mesh2(vertices2, indices);
	ProjectHydrogen::Shader shader(vertexShaderSource, fragmentShaderSource);
	ProjectHydrogen::Shader shader2(vertexShaderSource, fragmentShaderSource2);

	// Render loop
	while (!glfwWindowShouldClose(window))
	{
		// Clear the screen
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw the square
		shader.Use();
		mesh.Draw();

		shader2.Use();
		mesh2.Draw();

		// Swap buffers and poll events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
