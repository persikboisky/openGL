#define WINDOW_NAME "openGL"

#include <GL/glew.h>
#include <iostream>

#include "window/Window.hpp"
#include "window/Event.hpp"
#include "graphics/Shader.hpp"
#include "graphics/VAO.hpp"
#include "file/JSON.hpp"

const int WINDOW_WIDTH = JSON::getValueFromJSON("./assets/config.json", "display-width");
const int WINDOW_HEIGHT = JSON::getValueFromJSON("./assets/config.json", "display-height");

//	-0.5f,  0.5f,  0.0f,
//	-0.5f, -0.5f,  0.0f,
//	 0.5f, -0.5f,  0.0f,
//
//	-0.5f,  0.5f,  0.0f,
//	 0.5f,  0.5f,  0.0f,
//	 0.5f, -0.5f,  0.0f
int main()
{

	Window::initializateWindow(WINDOW_NAME, WINDOW_WIDTH, WINDOW_HEIGHT);
	CreateShaderProgram First("./assets/shaders/main.glslv", "./assets/shaders/main.glslf");
	VAO objVAO;

	objVAO.addVBO(
		{
			//x      y      z
			-0.5f,  0.5f,  0.0f,
			-0.5f, -0.5f,  0.0f,
			 0.5f, -0.5f,  0.0f,

			-0.5f,  0.5f,  0.0f,
			 0.5f,  0.5f,  0.0f,
			 0.5f, -0.5f,  0.0f
		}
	);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	 
	while (!Window::isCloseWindow())
	{

		Event::update();
		glClear(GL_COLOR_BUFFER_BIT);

		First.use();
		First.setValueUniformF(1.0f, "red");
		First.setValueUniformF(0.5f, "green");
		First.setValueUniformF(0.5f, "blue");

		objVAO.draw(6);

		Window::swapBuffer();
	}

	First.Delete();
	Window::terminate();
	return 0;
}