/*
 * PNG.cpp
 *
 * Created on Dec 04, 2024
 *         Author: persikboisky
 */

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <iostream>

#include "PNG.hpp"

int png::width, png::height, png::channels;

unsigned char* png::loadPNG(const char* PATH)
{
	unsigned char* image = stbi_load(PATH, &png::width, &png::height, &png::channels, STBI_default);
	if (image != 0) {
		std::cout << "OK load png: " << PATH << std::endl;
	}
	else
	{
		std::cerr << "FAILED load png: " << PATH << std::endl;
	}
	return image;
}