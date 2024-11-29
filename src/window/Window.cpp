/*
 * Window.cpp
 *
 * Created on Nov 23, 2024
 *         Author: persikboisky
 */

#define VERSION_MAJOR 4
#define VERSION_MINOR 6

#include "Window.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow* Window::window;

int Window::initializateWindow(const char* title, int width, int height)
{
	if (glfwInit())
	{
		std::cout << "OK: initializate GLFW" << std::endl;
	}
	else
	{
		std::cerr << "FAILED: initializate GLFW" << std::endl;
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr)
	{
		std::cerr << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	else
	{
		std::cout << "OK: to create GLFW Window" << std::endl;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	GLenum glewErr = glewInit();
	if (glewErr != GLEW_OK)
	{
		if (glewErr == GLEW_ERROR_NO_GLX_DISPLAY)
		{
			std::cerr << "Failed initializate GLEW error 240" << std::endl;
			// see issue #240
		}
		else
		{
			std::cerr << "Failed initializate GLEW" << std::endl;
			return -1;
		}
	}
	else
	{
		std::cout << "OK: initializate GLEW" << std::endl;
	}

	glViewport(0, 0, width, height);
}

void Window::terminate()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Window::isCloseWindow()
{
	glfwPollEvents();
	return glfwWindowShouldClose(window);
}

void Window::setShouldClose(bool flag)
{
	glfwSetWindowShouldClose(window, flag);
}

void Window::swapBuffer()
{
	glfwSwapBuffers(window);
}