#include "SandboxLayer.h"
#include "CLEngine.h"
#include "RenderSystem.h"

std::vector<Cloudscape::Lightning::Vertex> cubeVertices =
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

std::vector<GLuint> cubeIndices =
{
  0, 1, 2,  0, 2, 3,        // +X
  4, 5, 6,  4, 6, 7,        // -X
  8, 9,10,  8,10,11,        // +Y
 12,13,14, 12,14,15,        // -Y
 16,17,18, 16,18,19,        // +Z
 20,21,22, 20,22,23         // -Z
};

float orbitTime = 0.0f;
float orbitRadius = 5.0f;


SandboxLayer::SandboxLayer()
  : cube(Cloudscape::Lightning::Mesh(cubeVertices, cubeIndices)),
  shader("shader/default.vert", "shader/default.frag"),
  camera()
{
  Cloudscape::CLEngine::Get().GetSystem<Cloudscape::RenderSystem>()->
    SetClearColor(glm::vec4(0.0f, 0.4f, 0.35f, 1.0f));
}

SandboxLayer::~SandboxLayer()
{

}

void SandboxLayer::Update(float dt)
{
  orbitTime += dt;

  float x = cosf(orbitTime) * orbitRadius;
  float z = sinf(orbitTime) * orbitRadius;


  camera.SetPosition({ x, 2.5f, z });
  
  shader.SetMat4("viewMat", camera.LookAt({ 0.0f, 0.0f, 0.0f }));
  shader.SetMat4("projMat", camera.GetProjMatrix());
}


void SandboxLayer::Draw()
{
  shader.Bind();
  cube.Bind();
  cube.Draw();
}