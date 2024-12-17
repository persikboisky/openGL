/*
 * Camera.hpp
 *
 * Created on Dec 11, 2024
 *         Author: persikboisky
 */

#ifndef WINDOW_CAMERA_H_
#define WINDOW_CAMERA_H_

#include <glm/glm.hpp>

class Camera {
public:
	static glm::vec3 x;
	static glm::vec3 y;
	static glm::vec3 z;
	static glm::vec3 pos;
	static glm::mat4 rot;

	static float fov;

	Camera(glm::vec3 pos, float fov);
	
	static void rotate(float x, float y, float z);
	static void resetRotate();
	static void move(float x, float y, float z);

	static glm::mat4 getView();
	static glm::mat4 getProj();
};
#endif /* WINDOW_CAMERA_HPP_ */