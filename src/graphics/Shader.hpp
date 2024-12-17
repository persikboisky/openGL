/*
 * Shader.hpp
 *
 * Created on Nov 24, 2024
 *         Author: persikboisky
 */

#ifndef GRAPHICS_SHADER_HPP_
#define GRAPHICS_SHADER_HPP_

#include <glm/glm.hpp>

// пред объявляем переменную из библиотеки glew
typedef unsigned int GLuint;

// создаём класс shader
struct shader
{
	static unsigned int id;
	static unsigned int getShaderProgram(const char* frag, const char* vert);
	static void select(unsigned int id);
	static void use();												
	static void Delete(unsigned int id);											
	static void setValueUniform(const float value, const char* name);
	static void setValueUniform(glm::mat4 matrix, const char* name);
};

#endif // GRAPHYCS_SHADER_HPP_