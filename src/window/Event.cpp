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
#include <iostream>

bool Event::key::Key[MAX_KEY_CODE];

void key_callbac(GLFWwindow *window, int key, int scancode, int action, int mod)
{
	if (action == GLFW_PRESS)
	{
		Event::key::Key[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		Event::key::Key[key] = false;
	}
}

void window_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
	Window::width = width;
	Window::height = height;
}

void Event::Init()
{
	glfwSetWindowSizeCallback(Window::window, window_size_callback);
}

bool Event::isCloseWindow()
{
	return glfwWindowShouldClose(Window::window); // получаем состояние окна
}

void Event::update()
{
	glfwPollEvents();
}

double Event::mouse::GetMouseCordX()
{
	double mouseX, mouseY;
	glfwGetCursorPos(Window::window, &mouseX, &mouseY);
	return mouseX;
}

double Event::mouse::GetMouseCordY()
{
	double mouseX, mouseY;
	glfwGetCursorPos(Window::window, &mouseX, &mouseY);
	return mouseY;
}

bool Event::mouse::GetMouseLeftButton()
{
	return glfwGetMouseButton(Window::window, GLFW_MOUSE_BUTTON_LEFT);
}

bool Event::mouse::GetMouseRightButton()
{
	return glfwGetMouseButton(Window::window, GLFW_MOUSE_BUTTON_RIGHT);
}

void Event::key::init()
{
	glfwSetKeyCallback(Window::window, key_callbac);
}

bool Event::key::getKey(int keyCode)
{
	if (keyCode >= sizeof(Event::key::Key)) std::cerr << "there is no such key in the buffer" << std::endl;

	else return Event::key::Key[keyCode];
}