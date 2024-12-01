

#include <glm/glm.hpp>

class Camera
{
public:

	glm::vec3 position;
	float fov;

	Camera(glm::vec3 position, float fov);
	~Camera();
};

