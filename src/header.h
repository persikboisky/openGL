/*
* header.h
*
* Created on Dec 05, 2024
*         Author: persikboisky
*/

#ifndef SRC_HEADER_H_
#define SRC_HEADER_H_

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>

#define WINDOW
#include "window/Window.hpp"
#include "window/Event.hpp"
#include "window/Camera.hpp"

#define GRAPHICS
#include "graphics/Shader.hpp"
#include "graphics/VAO.hpp"
#include "graphics/Texture.hpp"

#define FILE
#include "file/JSON.hpp"
#include "file/PNG.hpp"

#endif // !SRC_HEADER_H_