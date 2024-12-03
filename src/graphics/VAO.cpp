/*
* VAO.hpp
*
* Created on Nov 30, 2024
*         Author: persikboisky
*/


#include "VAO.hpp"

#include <GL/glew.h>
#include <iostream>
#include <vector>

GLuint VAO::vao;
std::vector<GLuint> VAO::vbo;

float verticies[] = {
	//x      y      z
	-0.5f,  0.5f,  0.0f,
	-0.5f, -0.5f,  0.0f,
	 0.5f, -0.5f,  0.0f,

	-0.5f,  0.5f,  0.0f,
	 0.5f,  0.5f,  0.0f,
	 0.5f, -0.5f,  0.0f
};

VAO::VAO()
{
	glGenVertexArrays(1, &vao);
}

VAO::~VAO()
{
	glDeleteVertexArrays(vbo.size(), &vao);
	glDeleteVertexArrays(1, &vao);
}

void VAO::bind()
{
	glBindVertexArray(vao);
}

void VAO::deBind()
{
	glBindVertexArray(0);
}

void VAO::addVBO(std::vector<float> data)
{
	GLuint bufferVBO;
	bind();

	glGenBuffers(1, &bufferVBO);
	glBindBuffer(GL_ARRAY_BUFFER, bufferVBO);
	glBufferData(GL_ARRAY_BUFFER, 5 * sizeof(float), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(vbo.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(vbo.size());
	deBind();
	vbo.push_back(bufferVBO);
}

void VAO::draw(GLsizei count)
{
	for (int i = 0; i < vbo.size(); i++) 
	{
		glEnableVertexAttribArray(i);
	}
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, count);
	glBindVertexArray(0);

	for (int i = 0; i < vbo.size(); i++) 
	{
		glDisableVertexAttribArray(i);
	}
} 