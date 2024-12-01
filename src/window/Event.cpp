/*
 * Window.ñpp
 *
 * Created on December 01, 2024
 *         Author: persikboisky
 */

#include "Event.hpp"
#include "Window.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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