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
	VAO objVAO;																	// создаём VAO

	// загружаем кординаты ввершин в VBO
	objVAO.addVBO(
		{// x    y     z     u     v
		 -0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 -0.5f, 0.5f, 0.0f,

		 0.5f, -0.5f, 0.0f,
		 -0.5f, 0.5f, 0.0f,
		 0.5f, 0.5f, 0.0f});

	glm::mat4 matrix(1.0f);
	matrix = glm::translate(matrix, glm::vec3(0.0f, 0.0f, 0.0f));
	matrix = glm::rotate(matrix, 0.5f, glm::vec3(1, 0, 0));

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // красим фон
	while (!Window::isCloseWindow())	  // главный цикл и проверка состояния окна
	{
		Event::update();			  // проверяем эвенты
		glClear(GL_COLOR_BUFFER_BIT); // чистим цветовой буфер

		First.use();							  // включаем шейдерную программу First
		First.setMatrixUniform(matrix, "matrix"); // загружаем матрицу в шейдерную прогрумму First, в переменную matrix
		First.setValueUniformF(1.0f, "red");	  // загружаем значение в шейдерную прогрумму First, в переменную red
		First.setValueUniformF(0.5f, "green");	  // загружаем значение в шейдерную прогрумму First, в переменную green
		First.setValueUniformF(0.5f, "blue");	  // загружаем значение в шейдерную прогрумму First, в переменную blue
		objVAO.draw(6);							  // рисуем фигуру с 6 вершинами используя VAO с названием obVAO
		Window::swapBuffer();					  // меняем буффера
	}

	First.Delete();		 // удоляем шейдерную прогрумму
	Window::terminate(); // удоляем окно
	return 0;
}