#define GLEW_STATIC
#include "../app/ExampleLayer.h"

#define __CSTL_WIDTH 400
#define __CSTL_HEIGHT 400
#define __CSTL_TITLE "Coastal Application"
#define __CSTL_COLOR 0.0f, 0.0f, 0.0f, 1.0f

int main()
{
	if (!glfwInit())
	{
		std::cout << "Failed to init glfw!\n";
		exit(1); // EXIT CODE 1 = GLFW INIT FAILURE
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	GLFWwindow* window = glfwCreateWindow(__CSTL_WIDTH, __CSTL_HEIGHT, __CSTL_TITLE, nullptr, nullptr);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to init glew!\n";
		exit(2); // EXIT CODE 2 = GLEW INIT FAILURE
	}

	ExampleLayer ex;
	ex.Start();
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(__CSTL_COLOR);
		glClear(GL_COLOR_BUFFER_BIT);

		ex.OnUpdate();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}