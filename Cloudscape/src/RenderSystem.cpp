#include "RenderSystem.h"
#include "CLEngine.h"
#include "PlatformSystem.h"
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

	void RenderSystem::BeginFrame()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void RenderSystem::EndFrame()
	{
		CLEngine::Get().GetSystem<PlatformSystem>()->SwapBuffers();
	}

	void RenderSystem::SetActiveCamera(Lightning::Camera camera)
	{
		m_activeCamera = &camera;
	}

	void RenderSystem::OnResize(unsigned width, unsigned height)
	{
		glViewport(0, 0, width, height);
		m_activeCamera->SetViewport(width, height);
	}

	void RenderSystem::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

}