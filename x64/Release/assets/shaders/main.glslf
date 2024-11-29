#version 460 core

out vec3 color; 

uniform float red;
uniform float green;
uniform float blue;

void main() 
{ 
    color = vec3(red, green, blue); 
} 