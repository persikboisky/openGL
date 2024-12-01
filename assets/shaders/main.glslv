#version 460 core 

layout(location = 0) in vec3 pos;

out vec4 a_color;

uniform mat4 matrix;

void main() 
{ 
    gl_Position = matrix * vec4(pos, 1.0); 
} 