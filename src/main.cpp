#define WINDOW_NAME "openGL" // имя окна

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>

#include "window/Window.hpp"
#include "window/Event.hpp"
#include "window/Camera.hpp"
#include "graphics/Shader.hpp"
#include "graphics/VAO.hpp"
#include "file/JSON.hpp"

const int WINDOW_WIDTH = JSON::getValueFromJSON("./assets/config.json", "display-width");	// получаем из JSON файла ширину окна
const int WINDOW_HEIGHT = JSON::getValueFromJSON("./assets/config.json", "display-height"); // получаем из JSON файла высоту окна

int main()
{

	Window::initializateWindow(WINDOW_NAME, WINDOW_WIDTH, WINDOW_HEIGHT);		// создаём окно
	Event::Init();																// инициализируем
	Shader First("./assets/shaders/main.glslv", "./assets/shaders/main.glslf"); // создаём шейдерную программу

	float vertices[] = {
		// x    y     z     u     v
		-1.0f,
		-1.0f,
		0.0f,
		0.0f,
		0.0f,
		1.0f,
		-1.0f,
		0.0f,
		1.0f,
		0.0f,
		-1.0f,
		1.0f,
		0.0f,
		0.0f,
		1.0f,

		1.0f,
		-1.0f,
		0.0f,
		1.0f,
		0.0f,
		1.0f,
		1.0f,
		0.0f,
		1.0f,
		1.0f,
		-1.0f,
		1.0f,
		0.0f,
		0.0f,
		1.0f,
	};

	// Create VAO
	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	glm::mat4 matrix(1.0f);

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // красим фон
	while (!Window::isCloseWindow())	  // главный цикл и проверка состояния окна
	{
		Event::update();			  // проверяем эвенты
		glClear(GL_COLOR_BUFFER_BIT); // чистим цветовой буфер

		First.use(); // включаем шейдерную программу First

		First.setValueUniform(1.0f, "red");	  // загружаем значение в шейдерную прогрумму First, в переменную red
		First.setValueUniform(0.5f, "green"); // загружаем значение в шейдерную прогрумму First, в переменную green
		First.setValueUniform(0.5f, "blue");  // загружаем значение в шейдерную прогрумму First, в переменную blue
		First.setValueUniform(matrix, "matrix");
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
		Window::swapBuffer(); // меняем буффера

		//std::cout << Event::Key::getKey[87] << std::endl;
	}

	First.Delete();		 // удоляем шейдерную прогрумму
	Window::terminate(); // удоляем окно
	return 0;
}