/*
 * Shader.hpp
 *
 * Created on Nov 24, 2024
 *         Author: persikboisky
 */

#ifndef GRAPHICS_SHADER_HPP_
#define GRAPHICS_SHADER_HPP_

typedef unsigned int GLuint;

class CreateShaderProgram
{
private:
	static unsigned int id;
	static GLuint locate;
	/*static GLuint BlockIndex;*/

public:
	static GLuint LoadShaders(const char* vertex_file, const char* fragment_file);
	static void use();
	static void Delete();
	static void setValueUniformF(const float value, const char* name);

	CreateShaderProgram(const char* frag, const char* vert);
	~CreateShaderProgram();
};

#endif // GRAPHYCS_SHADER_HPP_