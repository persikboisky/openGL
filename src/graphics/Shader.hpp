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
class Shader
{
private:
	// пред объявляем переменную для хранения номера шейд-ной программы
	static unsigned int id;

public:
	// пред объявляем:
	static void use();												   // функцию для включения шейд-ной программы
	static void Delete();											   // функцию для удаления шейд-ной программы
	static void setValueUniform(const float value, const char *name);  // функцию для передачи float uniform переменной в шейдер
	static void setValueUniform(glm::mat4 matrix, const char* name);   // функцию для передачи matrix4 uniform переменной в шейдер

	Shader(const char *frag, const char *vert); // конструктор (принимает путь к фраг-му и верш-му шейдеру)
	~Shader();									// деструктор
};

#endif // GRAPHYCS_SHADER_HPP_