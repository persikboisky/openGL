#version 460 core

out vec4 f_color;

in vec3 v_pos;
in vec3 v_normal;
in vec2 v_textCoord;

uniform vec4 u_color;
uniform sampler2D tex_diffuse;

vec3 light_pos = vec3(0, 3, 0);

void main() {
	vec3 lightColor = vec3(1, 1, 1);
	float ambientStrength = 0.8f;

    vec3 ambient = ambientStrength * lightColor;

	vec3 norm = normalize(v_normal);
	vec3 lightDir = normalize(light_pos - v_pos);

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	vec3 result = (ambient + diffuse) * u_color.xyz;
	f_color = vec4(result, 1.0f) * texture(tex_diffuse, v_textCoord);
}