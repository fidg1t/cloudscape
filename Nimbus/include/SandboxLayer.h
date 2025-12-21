#pragma once

#include "CLLayer.h"
#include "glm/glm.hpp"
#include "glad/glad.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
#include "Transform.h"

struct Entity
{
	Entity() = default;

	Cloudscape::Lightning::Mesh* mesh;
	Cloudscape::Transform transform = Cloudscape::Transform();
};

class SandboxLayer : public Cloudscape::CLLayer
{
public:
	SandboxLayer();
	virtual ~SandboxLayer();

	void OnEvent(Cloudscape::Event& event) override;

	void Load() override;
	void Update(float dt) override;
	void Draw() override;

private:
	Entity cube;
	Cloudscape::Lightning::Shader shader;
	Cloudscape::Lightning::Camera camera;
};