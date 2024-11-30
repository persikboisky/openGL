/*
* VAO.hpp
*
* Created on Nov 30, 2024
*         Author: persikboisky
*/

#include <vector>

typedef int GLsizei;
typedef unsigned int GLuint;

class VAO
{
public:
	static GLuint vao;
	static std::vector<GLuint> vbo;
	VAO();
	~VAO();
	static void bind();
	static void deBind();
	static void addVBO(std::vector<float> data);
	static void draw(GLsizei count);
};