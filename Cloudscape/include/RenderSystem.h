#pragma once

#include "CLSystem.h"
#include "Camera.h"
#include "glm/glm.hpp"

namespace Cloudscape {

	class CLAPI RenderSystem : public CLSystem
	{
	public:
		RenderSystem();
		~RenderSystem();

		void Load() override;

		void BeginFrame();
		void EndFrame();

		void SetActiveCamera(Lightning::Camera camera);

		void OnResize(unsigned width, unsigned height);

		void SetClearColor(const glm::vec4& color);
	private:
		Lightning::Camera* m_activeCamera = nullptr;

		glm::vec4 m_clearColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	};

}