#version 460 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 textCoord;

out vec3 v_pos;
out vec3 v_normal;
out vec2 v_textCoord;

uniform vec3 u_position;
uniform mat4 view_proj;

void main() {
	vec4 pos = view_proj * vec4(u_position + position, 1.0);
	//pos = t_matrix * pos;
	v_pos = pos.xyz;
	v_normal = normal;
	v_textCoord = textCoord;
	gl_Position = pos;
}