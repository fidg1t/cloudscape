#version 460 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 nrm;
layout (location = 2) in vec2 uv;

uniform mat4 projMat;
uniform mat4 viewMat;

out vec3 normal;

void main()
{
  normal = nrm;
  gl_Position =  projMat * viewMat * vec4(pos, 1.0);
}