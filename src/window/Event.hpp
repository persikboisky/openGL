/*
 * Window.hpp
 *
 * Created on December 01, 2024
 *         Author: persikboisky
 */

#ifndef WINDOW_EVENT_HPP_
#define WINDOW_EVENT_HPP_

#define MAX_KEY_CODE 360

// создаём пространство имён
namespace Event
{
	void Init(); // функция инициализации
	bool isCloseWindow();
	void update(); // функция проверки эвентов
	struct mouse;  // предобявление структуры с функциями для мыши
	struct key;

	// static struct Key;
};

struct Event::mouse
{
	// пред объявляем:
	static double GetMouseCordY();	   // функция определяющая кординату курсора по осиY
	static double GetMouseCordX();	   // функция определяющая кординату курсора по осиX
	static bool GetMouseLeftButton();  // функция проверяющая нажатие левой кнопки мыши
	static bool GetMouseRightButton(); // функция проверяющая нажатие правой кнопки мыши
};

struct Event::key
{
	static bool Key[MAX_KEY_CODE];
	static void init();
	static bool getKey(int keyCode);
};

#endif // !WINDOW_EVENT_HPP_