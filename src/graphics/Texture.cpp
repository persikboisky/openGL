#include <GL/glew.h>
#include <iostream>
#include <vector>
#include "Texture.hpp"
#include "../load/PNG.hpp"

std::vector<GLuint> texture::id;

void texture::use(int n)
{
	if (n >= id.size()) 
	{
		std::cerr << "Failed bind texture: " << n << std::endl;
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, id[n]);
	}
}

void texture::useByID(unsigned int id)
{
	bool flag = false;
	unsigned char size = texture::id.size();
	for (int i = 0; i < size; i++)
	{
		if (texture::id[i] != id) flag = false;
		else
		{
			flag = true;
			i = size;
		}
	}

	if (flag) glBindTexture(GL_TEXTURE_2D, id);
	else std::cerr << "Failed bind texture: " << id << std::endl;
}

int texture::addTexture(unsigned char* texture, int width, int height, int channels)
{
	GLuint Texture;
	glGenTextures(1, &Texture);

	if (Texture > 0)
	{
		std::cout << "OK add Texture: id->" << Texture << std::endl;
	}
	else
	{
		std::cerr << "Failed add Texture" << std::endl;
		return -1;
	}

	glBindTexture(GL_TEXTURE_2D, Texture);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	if (channels == 4) 
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);
	}
	else if (channels == 3) 
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	id.push_back(Texture);

	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return 1;
}

unsigned int texture::loadText(const char* path)
{
	int textConfig[3];
	unsigned char* text = png::loadPNG(path, textConfig[0], textConfig[1], textConfig[2]);
	unsigned int id = texture::addTexture(text, textConfig[0], textConfig[1], textConfig[2]);
	png::Delete(text);
	return id;
}

void texture::Delete(GLuint n)
{
	if (n >= id.size())
	{
		std::cerr << "Failed bind texture: " << n << std::endl;
	}
	else
	{
		glDeleteTextures(1, &id[n]);
		id[n] = 0;
	}
}

void texture::allDelete()
{
	for (int i = 0; i < id.size(); i++)
	{
		glDeleteTextures(1, &id[i]);
	}
	id.clear();
}