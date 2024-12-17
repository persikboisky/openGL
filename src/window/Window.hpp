/*
 * Window.hpp
 *
 * Created on Nov 23, 2024
 *         Author: persikboisky
 */

#ifndef WINDOW_WINDOW_HPP_
#define WINDOW_WINDOW_HPP_

// предобъявляем класс окна
class GLFWwindow;

// создаём структуру окна
struct Window
{
public:
	// предобъявления:
	static GLFWwindow *window;												 // предобъявление окна
	static int width;														 // хранит ширину окна
	static int height;														 // хранит высоту окна
	static int initializateWindow(const char *title, int width, int height); // инициализация окна
	static void setWindowIcon(const char* path);
	static void terminate();												 // удоление окна
	static void swapBuffer();												 // смена буфера
	static void setShouldClose(bool flag);									 // принудительное закрытие окна
};

#endif // WINDOW_WINDOW_HPP_