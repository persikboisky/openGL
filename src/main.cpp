#define WINDOW_NAME "openGL"

#include <GL/glew.h>
#include <iostream>

#include "window/Window.hpp"
#include "graphics/Shader.hpp"
#include "file/JSON.hpp"

const int WINDOW_WIDTH = JSON::getValueFromJSON("./assets/config.json", "display-width");
const int WINDOW_HEIGHT = JSON::getValueFromJSON("./assets/config.json", "display-height");

float verticies[] = {
	//x      y      z
	-0.5f,  0.5f,  0.0f,
	-0.5f, -0.5f,  0.0f,
	 0.5f, -0.5f,  0.0f,

	-0.5f,  0.5f,  0.0f,
	 0.5f,  0.5f,  0.0f,
	 0.5f, -0.5f,  0.0f
};

int main()
{

	Window::initializateWindow(WINDOW_NAME, WINDOW_WIDTH, WINDOW_HEIGHT);
	CreateShaderProgram First("./assets/shaders/main.glslv", "./assets/shaders/main.glslf");

	GLuint VAO, VBO;

	//VAO::createVAO(1);
	//VAO::createVBO(1);
	//VAO::setValueVBO(0, verticies);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLfloat*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	glClearColor(0.6f, 0.62f, 0.65f, 1);
	 
	while (!Window::isCloseWindow())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		First.use();
		First.setValueUniformF(1.0f, "red");
		First.setValueUniformF(0.5f, "green");
		First.setValueUniformF(0.5f, "blue");

		glBindVertexArray(VAO);
		//VAO::use();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

		Window::swapBuffer();
	}

	First.Delete();
	Window::terminate();
	return 0;
}