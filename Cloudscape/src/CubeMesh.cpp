#include "CubeMesh.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

struct Vertex
{
  glm::vec3 vert;
  glm::vec3 norm;
  glm::vec2 uv;
};

Vertex cubeVertices[] =
{
  // +X (right)
  { { 0.5f, -0.5f, -0.5f }, {  1.0f,  0.0f,  0.0f }, { 0.0f, 0.0f } },
  { { 0.5f,  0.5f, -0.5f }, {  1.0f,  0.0f,  0.0f }, { 1.0f, 0.0f } },
  { { 0.5f,  0.5f,  0.5f }, {  1.0f,  0.0f,  0.0f }, { 1.0f, 1.0f } },
  { { 0.5f, -0.5f,  0.5f }, {  1.0f,  0.0f,  0.0f }, { 0.0f, 1.0f } },

  // -X (left)
  { { -0.5f, -0.5f,  0.5f }, { -1.0f,  0.0f,  0.0f }, { 0.0f, 0.0f } },
  { { -0.5f,  0.5f,  0.5f }, { -1.0f,  0.0f,  0.0f }, { 1.0f, 0.0f } },
  { { -0.5f,  0.5f, -0.5f }, { -1.0f,  0.0f,  0.0f }, { 1.0f, 1.0f } },
  { { -0.5f, -0.5f, -0.5f }, { -1.0f,  0.0f,  0.0f }, { 0.0f, 1.0f } },

  // +Y (top)
  { { -0.5f,  0.5f, -0.5f }, {  0.0f,  1.0f,  0.0f }, { 0.0f, 0.0f } },
  { { -0.5f,  0.5f,  0.5f }, {  0.0f,  1.0f,  0.0f }, { 0.0f, 1.0f } },
  { {  0.5f,  0.5f,  0.5f }, {  0.0f,  1.0f,  0.0f }, { 1.0f, 1.0f } },
  { {  0.5f,  0.5f, -0.5f }, {  0.0f,  1.0f,  0.0f }, { 1.0f, 0.0f } },

  // -Y (bottom)
  { { -0.5f, -0.5f,  0.5f }, {  0.0f, -1.0f,  0.0f }, { 0.0f, 0.0f } },
  { { -0.5f, -0.5f, -0.5f }, {  0.0f, -1.0f,  0.0f }, { 0.0f, 1.0f } },
  { {  0.5f, -0.5f, -0.5f }, {  0.0f, -1.0f,  0.0f }, { 1.0f, 1.0f } },
  { {  0.5f, -0.5f,  0.5f }, {  0.0f, -1.0f,  0.0f }, { 1.0f, 0.0f } },

  // +Z (front)
  { { -0.5f, -0.5f,  0.5f }, {  0.0f,  0.0f,  1.0f }, { 0.0f, 0.0f } },
  { {  0.5f, -0.5f,  0.5f }, {  0.0f,  0.0f,  1.0f }, { 1.0f, 0.0f } },
  { {  0.5f,  0.5f,  0.5f }, {  0.0f,  0.0f,  1.0f }, { 1.0f, 1.0f } },
  { { -0.5f,  0.5f,  0.5f }, {  0.0f,  0.0f,  1.0f }, { 0.0f, 1.0f } },

  // -Z (back)
  { {  0.5f, -0.5f, -0.5f }, {  0.0f,  0.0f, -1.0f }, { 0.0f, 0.0f } },
  { { -0.5f, -0.5f, -0.5f }, {  0.0f,  0.0f, -1.0f }, { 1.0f, 0.0f } },
  { { -0.5f,  0.5f, -0.5f }, {  0.0f,  0.0f, -1.0f }, { 1.0f, 1.0f } },
  { {  0.5f,  0.5f, -0.5f }, {  0.0f,  0.0f, -1.0f }, { 0.0f, 1.0f } },
};

unsigned int cubeIndices[] =
{
  0, 1, 2,  0, 2, 3,        // +X
  4, 5, 6,  4, 6, 7,        // -X
  8, 9,10,  8,10,11,        // +Y
 12,13,14, 12,14,15,        // -Y
 16,17,18, 16,18,19,        // +Z
 20,21,22, 20,22,23         // -Z
};

struct Camera
{
  glm::vec3 position{ 0.0f, 0.0f, 3.0f }; // back by 10
  glm::vec3 target{ 0.0f, 0.0f, 0.0f };
  glm::vec3 up{ 0.0f, 1.0f, 0.0f };

  float fov = glm::radians(60.0f);
  float aspect = 6.0f / 9.0f;
  float nearZ = 0.1f;
  float farZ = 100.0f;

  glm::mat4 GetView() const
  {
    return glm::lookAt(position, target, up);
  }

  glm::mat4 GetProj() const
  {
    return glm::perspective(fov, aspect, nearZ, farZ);
  }
};


namespace Cloudscape {

  CubeMesh::CubeMesh()
  {
    std::ifstream file("shader/default.vert", std::ios::in);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();
    const char* vertShaderSource = source.c_str();

    std::cout << std::filesystem::current_path() << std::endl;

    vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vertShaderSource, nullptr);
    glCompileShader(vertShader);

    GLint success = 0;
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      char infoLog[1024];
      glGetShaderInfoLog(vertShader, sizeof(infoLog), nullptr, infoLog);
      CL_ERROR("Vertex shader compile error:\n" + std::string(infoLog));
      assert(0);
    }

    buffer.str("");
    buffer.clear();
    file = std::ifstream("shader/default.frag");
    buffer << file.rdbuf();
    source = buffer.str();
    const char* fragShaderSource = source.c_str();

    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragShaderSource, nullptr);
    glCompileShader(fragShader);

    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      char infoLog[1024];
      glGetShaderInfoLog(fragShader, sizeof(infoLog), nullptr, infoLog);
      CL_ERROR("Fragment shader compile error:\n" + std::string(infoLog));
      assert(0);
    }

    program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
      char infoLog[1024];
      glGetProgramInfoLog(program, sizeof(infoLog), nullptr, infoLog);
      CL_ERROR("Shader link error:\n" + std::string(infoLog));
      assert(0);
    }

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);


    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, vert));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, norm));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
  }

  void CubeMesh::Draw()
  {
    Camera camera;
    camera.aspect = 1600 / float(900);

    glm::mat4 view = camera.GetView();
    glm::mat4 proj = camera.GetProj();

    glUseProgram(program);

    glUniformMatrix4fv(
      glGetUniformLocation(program, "viewMat"),
      1, GL_FALSE, &view[0][0]
    );

    glUniformMatrix4fv(
      glGetUniformLocation(program, "projMat"),
      1, GL_FALSE, &proj[0][0]
    );


    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(std::size(cubeIndices)), GL_UNSIGNED_INT, 0);
  }
}