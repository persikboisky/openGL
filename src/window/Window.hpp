/*
 * Window.hpp
 *
 * Created on Nov 23, 2024
 *         Author: persikboisky
 */

#ifndef WINDOW_WINDOW_HPP_
#define WINDOW_WINDOW_HPP_

class GLFWwindow;

struct Window
{
public:
	static GLFWwindow* window;
	static int initializateWindow(const char* title, int width, int height);
	static void terminate();
	static void swapBuffer();
	static bool isCloseWindow();
	static void setShouldClose(bool flag);
};

#endif // WINDOW_WINDOW_HPP_