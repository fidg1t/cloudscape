#pragma once

#include "CLLayer.h"
#include "glm/glm.hpp"

class SandboxLayer : public Cloudscape::CLLayer
{
public:
	SandboxLayer();
	virtual ~SandboxLayer();

	virtual void Update(float dt) override;
	virtual void Draw() override;
private:
	glm::vec4 color;
	float timer;
};