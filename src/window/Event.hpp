/*
 * Window.hpp
 *
 * Created on December 01, 2024
 *         Author: persikboisky
 */

#ifndef WINDOW_EVENT_HPP_
#define WINDOW_EVENT_HPP_

#define MAX_KEY_CODE 255

// создаём пространство имён
namespace Event
{
	void Init();		 // функция инициализации
	void update();		 // функция проверки эвентов
	static struct Mouse; // предобявление структуры с функциями для мышь
	static struct Key;

	// static struct Key;
};

struct Event::Mouse
{
	// пред объявляем:
	static double GetMouseCordY();	   // функция определяющая кординату курсора по осиY
	static double GetMouseCordX();	   // функция определяющая кординату курсора по осиX
	static bool GetMouseLeftButton();  // функция проверяющая нажатие левой кнопки мыши
	static bool GetMouseRightButton(); // функция проверяющая нажатие правой кнопки мыши
};

struct Event::Key
{
public:
	// const unsigned char maxKey = MAX_KEY_CODE;
	static bool getKey[MAX_KEY_CODE];
};

#endif // !WINDOW_EVENT_HPP_