#pragma once

#include "CLLayer.h"
#include "glm/glm.hpp"
#include "glad/glad.h"
#include "CubeMesh.h"

class SandboxLayer : public Cloudscape::CLLayer
{
public:
	SandboxLayer();
	virtual ~SandboxLayer();

	virtual void Update(float dt) override;
	virtual void Draw() override;

private:
	Cloudscape::CubeMesh cube;
};