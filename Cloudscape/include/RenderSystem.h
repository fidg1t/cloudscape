#pragma once

#include "CLSystem.h"
#include "glm/glm.hpp"

namespace Cloudscape {

	class CLAPI RenderSystem : public CLSystem
	{
	public:
		RenderSystem();
		~RenderSystem();

		void Load() override;
		void Draw() override;

		void SetClearColor(const glm::vec4& color);
	private:
		glm::vec4 m_clearColor;
	};

}