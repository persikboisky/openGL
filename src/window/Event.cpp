/*
 * Window.�pp
 *
 * Created on December 01, 2024
 *         Author: persikboisky
 */

#include "Event.hpp"
#include "Window.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

bool Event::Key::getKey[MAX_KEY_CODE];

void key_callbac(GLFWwindow *window, int key, int scancode, int action, int mod)
{
	if (action == GLFW_PRESS)
	{
		Event::Key::getKey[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		Event::Key::getKey[key] = false;
	}
}

void window_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
	Window::WIDTH = width;
	Window::HEIGHT = height;
}

void Event::Init()
{
	glfwSetWindowSizeCallback(Window::window, window_size_callback);
	glfwSetKeyCallback(Window::window, key_callbac);
}

void Event::update()
{
	glfwPollEvents();
}

double Event::Mouse::GetMouseCordX()
{
	double mouseX, mouseY;
	glfwGetCursorPos(Window::window, &mouseX, &mouseY);
	return mouseX;
}

double Event::Mouse::GetMouseCordY()
{
	double mouseX, mouseY;
	glfwGetCursorPos(Window::window, &mouseX, &mouseY);
	return mouseY;
}

bool Event::Mouse::GetMouseLeftButton()
{
	return glfwGetMouseButton(Window::window, GLFW_MOUSE_BUTTON_LEFT);
}

bool Event::Mouse::GetMouseRightButton()
{
	return glfwGetMouseButton(Window::window, GLFW_MOUSE_BUTTON_RIGHT);
}