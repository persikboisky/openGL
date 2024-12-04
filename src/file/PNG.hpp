/*
 * PNG.hpp
 *
 * Created on Dec 04, 2024
 *         Author: persikboisky
 */

#ifndef GRAPHICS_PNG_HPP_
#define RAPHICS_PNG_HPP_

struct png
{
	static int width, height, channels;
	static unsigned char* loadPNG(const char* PATH);
};

#endif // !GRAPHICS_PNG_HPP_