/*
 * Window.cpp
 *
 * Created on Nov 23, 2024
 *         Author: persikboisky
 */

#define VERSION_MAJOR 4		  // первая цифра в версии openGL
#define VERSION_MINOR 6		  // вторая цифра в версии openGL
#define WINDOW_RESIZABLE true // разрешение на изменнения маштаба окна

#include "Window.hpp"
#include "../load/PNG.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow *Window::window; // объявляем объект окно
int Window::height = 0;
int Window::width = 0;

int Window::initializateWindow(const char *title, int width, int height)
{
	// инециализируем и проверяем glfw
	if (glfwInit())
	{
		std::cout << "OK: initializate GLFW" << std::endl;
	}
	else
	{
		std::cerr << "FAILED: initializate GLFW" << std::endl;
		return -1;
	}
	// настраиваем openGL для данного окна
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, WINDOW_RESIZABLE);

	// создаём и проверяем окно на ошибки
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

	Window::width = width;
	Window::height = height;

	// создаём контекст окна
	glfwMakeContextCurrent(window);

	// включаем эксперементальные возможности
	glewExperimental = GL_TRUE;

	// инециализируем и проверяем glew
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

	// уточняем размер окна
	glViewport(0, 0, width, height);
}

void Window::setWindowIcon(const char* path)
{
	GLFWimage images[1];

	int width, height, channels;
	unsigned char* img = png::loadPNG(path, width, height, channels);

	images[0].width = width;
	images[0].height = height;
	images[0].pixels = img;

	glfwSetWindowIcon(window, 1, images);
	free(images[0].pixels);
}

void Window::terminate()
{
	glfwDestroyWindow(window); // удоляем окно
	glfwTerminate();		   // выходим из glfw
}

void Window::setShouldClose(bool flag)
{
	glfwSetWindowShouldClose(window, flag); // передаём состояние окна
}

void Window::swapBuffer()
{
	glfwSwapBuffers(window); // сменяем буфферы
}