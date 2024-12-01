/*
 * Shader.hpp
 *
 * Created on Nov 24, 2024
 *         Author: persikboisky
 */

#ifndef GRAPHICS_SHADER_HPP_
#define GRAPHICS_SHADER_HPP_

#include <GLM/glm.hpp>

typedef unsigned int GLuint;

class Shader
{
private:
	static unsigned int id;
	static GLuint locate;

public:
	static void use();
	static void Delete();
	static void setValueUniformF(const float value, const char* name);
	static void setMatrixUniform(glm::mat4 matrix, const char* name);

	Shader(const char* frag, const char* vert);
	~Shader();
};

#endif // GRAPHYCS_SHADER_HPP_