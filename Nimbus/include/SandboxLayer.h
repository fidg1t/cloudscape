#pragma once

#include "CLLayer.h"
#include "glm/glm.hpp"
#include "glad/glad.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"

class SandboxLayer : public Cloudscape::CLLayer
{
public:
	SandboxLayer();
	virtual ~SandboxLayer();

	virtual void Update(float dt) override;
	virtual void Draw() override;

private:
	Cloudscape::Lightning::Mesh cube;
	Cloudscape::Lightning::Shader shader;
	Cloudscape::Lightning::Camera camera;
};