#pragma once

#include "Core.h"
#include "glm/glm.hpp"

namespace Cloudscape {

	class CLAPI Transform
	{
	public:
		Transform(glm::vec3 pos = glm::vec3(0.0f),
							glm::vec3 scale = glm::vec3(1.0f),
							glm::vec3 rotation = glm::vec3(0.0f));
		~Transform();

		void SetPosition(glm::vec3 position);
		void SetScale(glm::vec3 scale);
		void SetRotation(glm::vec3 rotation);

		glm::vec3 GetPosition() const;
		glm::vec3 GetScale() const;
		glm::vec3 GetRotation() const;

		glm::mat4 GetModelingTransform() const;

	private:
		glm::vec3 m_pos, m_scale, m_rotation;
	};
		
}