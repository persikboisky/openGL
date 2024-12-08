#define WINDOW_NAME "openGL" // имя окна

#include "header.h"

const int WINDOW_WIDTH = JSON::getValueFromJSON("./assets/config.json", "display-width");	// получаем из JSON файла ширину окна
const int WINDOW_HEIGHT = JSON::getValueFromJSON("./assets/config.json", "display-height"); // получаем из JSON файла высоту окна

char unsigned* iconWindow = png::loadPNG("./assets/img/icon.png");

int main()
{

	Window::initializateWindow(WINDOW_NAME, WINDOW_WIDTH, WINDOW_HEIGHT);		// создаём окно
	Window::setWindowIcon(iconWindow, png::width, png::height);
	Event::Init();																// инициализируем
	unsigned int shaderPR = shader::getShaderProgram("./assets/shaders/main.glslf", "./assets/shaders/main.glslv");

	char unsigned* pixel = png::loadPNG("./assets/img/test.png");
	int widthT = png::width, heightT = png::height, channels = png::channels;

	float vertices[] = {
		// x    y     z     u     v
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,

		1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	};

	// Create VAO
	GLuint VAO, VBO;

	texture::addTexture(pixel, widthT, heightT, channels);

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

	glm::mat4 matrix(1.0f), model(1.0f);
	model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // красим фон
	while (!Window::isCloseWindow())	  // главный цикл и проверка состояния окна
	{

		Event::update();			  // проверяем эвенты
		glClear(GL_COLOR_BUFFER_BIT); // чистим цветовой буфер

		shader::use(shaderPR);
		texture::use(0);
		shader::setValueUniform(shaderPR, matrix, "matrix");
		shader::setValueUniform(shaderPR, model, "model");

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

		Window::swapBuffer(); // меняем буфера

		//std::cout << Event::Key::getKey[87] << std::endl;
	}

	texture::allDelete(); 
	shader::Delete(shaderPR);		 // удаляем шейдерную программу
	Window::terminate(); // удаляем окно
	return 0;
}