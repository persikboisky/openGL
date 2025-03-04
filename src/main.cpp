#include "core/core.h"
#include "Player.h"
#include <vector>
#include <array>
#include <algorithm> 

double mouseX, mouseY;
bool key[7];
bool cursor = false;
int tic = 0;

float v_r = -0.25f;
float v_g = 0.0f;
float v_b = 0.0f;

float r = 1.0f;
float g = 1.0f;
float b = 1.0f;

int main()
{

	try
	{

		core::Init();
		//create window
		Window window("openGL", 1280, 720);
		window.setContext();

		VAO* bongo = new VAO(vao::FileOBJtoVVO("./res/obj/ak-47/ak-47.obj", true, true), 8);
		bongo->addAttribute(0, 3, 0);
		bongo->addAttribute(1, 3, 3);
		bongo->addAttribute(2, 2, 6);

		VAO* Smoke = new VAO(vao::FileOBJtoVVO("./res/obj/smoke/smoke.obj", true, true), 8);
		Smoke->addAttribute(0, 3, 0);
		Smoke->addAttribute(1, 3, 3);
		Smoke->addAttribute(2, 2, 6);
		 
		//Shader* shader = new Shader("./res/shaders/mainv.glsl", "./res/shaders/mainf.glsl");
		Shader* shader_2 = new Shader("./res/shaders/mainv.glsl", "./res/shaders/main2f.glsl");

		unsigned int Texture = texture::load("./res/obj/ak-47/ak74m_2DView.png");
		unsigned int TextureSmoke = texture::load("./res/obj/smoke/BTV_1_BaseColor.png");

		//creat player
		Player persikboisky(0, 0, 4, 70);

		glEnable(GL_DEPTH_TEST);

		//game Circle
		while (!window.event->close())
		{
			window.event->update();
			if (window.event->getKey(K_ESCAPE))
			{
				window.close();
			}

			if (!cursor)
			{
				window.cursor->getCordCursor(mouseX, mouseY);
				window.cursor->setPosition(0, 0);
			}
			window.cursor->disableCursor(!cursor);

			key[0] = window.event->getKey(K_W);
			key[1] = window.event->getKey(K_S);
			key[2] = window.event->getKey(K_A);
			key[3] = window.event->getKey(K_D);
			key[6] = window.event->getKey(K_SPACE);
			key[4] = window.event->getKey(K_LEFT_SHIFT);
			key[5] = window.event->getKey(K_LEFT_CONTROL);

			if (window.event->getKey(K_ESCAPE))
			{
				window.close();
			}
			if (window.event->getKey(K_F1) && tic > 75)
			{
				tic = 0;
				cursor = !cursor;
			}
			tic += 1;
			if (tic >= 10000000) tic = 100;

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.5, 0.5, 0.5, 0);

			shader_2->use();

			persikboisky.move(key);
			persikboisky.render("view", "proj", window.width, window.height, mouseX, mouseY);

			shader_2->Uniform3F(glm::vec3(0, 0, 0), "u_position");
			shader_2->Uniform4F(glm::vec4(1, 1, 1, 1), "u_color");
			texture::bind(Texture);
			bongo->draw(TRIANGLE_STRIP);

			shader_2->Uniform3F(glm::vec3(0, 0, -0.5), "u_position");
			texture::bind(TextureSmoke);
			Smoke->draw(TRIANGLE_STRIP);

			window.swapBuffers();
			window.setSizeBuffer(window.width, window.height);
		}
		texture::DeleteALL();
		vao::DeleteALL();
		shader::DeleteALL();
	}
	catch (...)
	{
		core::Terminate();
		return -1;
	}

	core::Terminate();
	return 0;
};