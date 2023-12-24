#include "../app/ExampleLayer.h"

int main()
{
	ExampleLayer ex;

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

	GLFWwindow* window = glfwCreateWindow(ex.GetWindowWidth(), ex.GetWindowHeight(), ex.GetWindowTitle().c_str(), nullptr, nullptr);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to init glew!\n";
		exit(2); // EXIT CODE 2 = GLEW INIT FAILURE
	}

	ex.Start();
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(ex.GetWindowColor().R, ex.GetWindowColor().G, ex.GetWindowColor().B, ex.GetWindowColor().A);
		glClear(GL_COLOR_BUFFER_BIT);

		ex.OnUpdate();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}