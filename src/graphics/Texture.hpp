/*
* VAO.hpp
*
* Created on Dec 06, 2024
*         Author: persikboisky
*/

#ifndef SRC_GRAPHICS_TEXTURE_HPP_
#define SRC_GRAPHICS_TEXTURE_HPP_

#include <vector>

typedef unsigned int GLuint;

struct texture
{
	static std::vector<GLuint> id;
	static int addTexture(unsigned char* texture, int width, int height, int channels);
	static unsigned int loadText(const char* path);
	static void use(int n);
	static void useByID(unsigned int id);
	static void Delete(GLuint id);
	static void allDelete();
};

#endif // !SRC_GRAPHICS_TEXTURE_HPP_
