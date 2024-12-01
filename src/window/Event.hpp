/*
 * Window.hpp
 *
 * Created on December 01, 2024
 *         Author: persikboisky
 */

#ifndef WINDOW_EVENT_HPP_
#define WINDOW_EVENT_HPP_

namespace Event
{
	void Init();
	void update();
	static struct Mouse;
};

struct Event::Mouse
{
	static double GetMouseCordY();
	static double GetMouseCordX();
	static bool GetMouseLeftButton();
	static bool GetMouseRightButton();
};

#endif // !WINDOW_EVENT_HPP_