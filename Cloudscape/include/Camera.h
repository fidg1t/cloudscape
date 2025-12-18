#pragma once

#include "Core.h"
#include "glm/glm.hpp"

namespace Cloudscape::Lightning {

	class CLAPI Camera
	{
	public:
		Camera(float fov = 90.0f, float aspect = 16.0f / 9.0f);
		~Camera();

		glm::mat4 LookAt(glm::vec3 lookPoint);

		void SetViewport(unsigned width, unsigned height);
		void SetPosition(glm::vec3 pos);
		void SetYaw(float angle);
		void SetPitch(float angle);
		void SetRoll(float angle);

		glm::vec3 GetPosition();
		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjMatrix();

	private:
		glm::vec4 m_eye;
		glm::vec4 m_up, m_right, m_back;

		float m_aspect;
		float m_fov;

		float m_np, m_fp;
	};

}