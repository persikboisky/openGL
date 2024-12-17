#pragma once

struct cursor
{
public:
	static void setCursorMode(int mode);
	static void showCursor(bool flag);
	static void disableCursor(bool flag);
	static void setPosition(double x, double y);
};