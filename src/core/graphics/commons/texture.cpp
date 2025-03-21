#define DEBUG true

#include "texture.hpp"
#include "../../util/vector.hpp"
#include "../../file/png.hpp"
#include <GL/glew.h>
#include <iostream>
#include <vector>

std::vector<unsigned int> texture::id;

void texture::bind(unsigned int id)
{
    glBindTexture(GL_TEXTURE_2D, id); 
}

unsigned int texture::load(unsigned char* image, int width, int height, int channels)
{
    GLuint Texture; 
    glGenTextures(1, &Texture); 

    bool flag = true;
    int index = vector::searchElemntForValue(id, 0);

    if (index != -1 && Texture != 0)
    {
        id[index] = Texture;
        flag = false;
    }

    if (flag)
    {
        if (Texture != 0)
        {
            texture::id.push_back(Texture);
            if (DEBUG) std::cout << "OK: create texture id: " << Texture << std::endl;
        }
        else
        {
            std::cerr << "Failed create Texture" << "\n";
            throw "FAILED_CREATE_VAO";
        }
    }

    bind(Texture);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    if (channels == 3) 
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    else if (channels == 4) 
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //(GL_LINEAR, GL_NEAREST)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //(GL_LINEAR, GL_NEAREST)

    bind(0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return Texture;
}

unsigned int texture::load(const char* path)
{
    int t_width;
    int t_height;
    int t_channels;

    unsigned char* text = png::load(path, t_width, t_height, t_channels);
    unsigned int texture_id = load(text, t_width, t_height, t_channels);

    png::Delete(text);

    return texture_id;
}

void texture::Delete(unsigned int id)
{
    glDeleteTextures(1, &id);
}

void texture::DeleteALL()
{
    for (int i = 0; i < id.size(); i++)
    {
        glDeleteTextures(1, &id[i]);
        //id[i] = 0;
        id.clear();
    }
}

#pragma Texture
Texture::Texture(const char* path)
{
    this->id = texture::load(path);
}

Texture::~Texture()
{
    texture::Delete(this->id);
}

void Texture::bind()
{
    texture::bind(this->id);
}