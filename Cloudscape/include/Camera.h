#pragma once

#include "Core.h"
#include "glm/glm.hpp"

namespace Cloudscape::Lightning {

	class CLAPI Camera
	{
	public:
		Camera(void);
		~Camera();

		void SetPosition(glm::vec3 pos);
		glm::mat4 LookAt(glm::vec3 lookPoint);

		void SetYaw(float angle);
		void SetPitch(float angle);
		void SetRoll(float angle);

		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjMatrix();

	private:
		glm::vec4 m_eye;
		glm::vec4 m_up, m_right, m_back;

		float m_vpWidth, m_vpHeight;
		float m_vpDist;

		float m_npDist, m_fpDist;
	};

}