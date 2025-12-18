#include "RenderSystem.h"
#include "glad/glad.h"
#include "glm/glm.hpp"

namespace Cloudscape {

	RenderSystem::RenderSystem()
	{

	}

	RenderSystem::~RenderSystem()
	{

	}

	void RenderSystem::Load()
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);
	}

	void RenderSystem::Draw()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void RenderSystem::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

}