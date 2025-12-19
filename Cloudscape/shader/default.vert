#version 460 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 nrm;
layout (location = 2) in vec2 uv;

uniform mat4 modelMat;
uniform mat4 projMat;
uniform mat4 viewMat;

out vec4 worldPosition;
out vec4 worldNormal;

void main()
{
  mat4 normalMat = inverse(transpose(modelMat));
  worldPosition = modelMat * vec4(pos, 1.0f);
  worldNormal = normalMat * vec4(nrm, 1.0f);
  gl_Position =  projMat * viewMat * worldPosition;
}