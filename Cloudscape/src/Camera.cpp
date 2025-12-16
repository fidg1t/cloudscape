#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"

namespace Cloudscape::Lightning {

	//TEMPORARY!! construct this better
	Camera::Camera(void)
	{
		m_right = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
		m_up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
		m_back = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
		m_eye = glm::vec4(0.0f, 0.0f, 9.0f, 1.0f);

		m_vpWidth = 2.0f;
		m_vpHeight = 2.0f;
		m_vpDist = 1.0f;

		m_npDist = 0.1f;
		m_fpDist = 10.0f;
	}

	Camera::~Camera()
	{
	
	}

	void Camera::SetPosition(glm::vec3 pos)
	{
		m_eye = glm::vec4(pos, 1.0f);
	}

	glm::mat4 Camera::LookAt(glm::vec3 lookPoint)
	{
		return glm::lookAt(glm::vec3(m_eye), lookPoint, glm::vec3(m_up));
	}

	void Camera::SetYaw(float angle)
	{
		glm::mat4 Rotation = glm::mat4(1.0f);
		Rotation = glm::rotate(Rotation, angle, glm::vec3(m_up));

		m_right = Rotation * m_right;
		m_back = Rotation * m_back;
	}
	
	void Camera::SetPitch(float angle)
	{
		glm::mat4 Rotation = glm::mat4(1.0f);
		Rotation = glm::rotate(Rotation, angle, glm::vec3(m_right));

		m_up = Rotation * m_up;
		m_back = Rotation * m_back;
	}

	void Camera::SetRoll(float angle)
	{
		glm::mat4 Rotation = glm::mat4(1.0f);
		Rotation = glm::rotate(Rotation, angle, glm::vec3(m_back));

		m_right = Rotation * m_right;
		m_up = Rotation * m_up;
	}

	glm::mat4 Camera::GetViewMatrix()
	{
		glm::mat4 view = glm::mat4(
			m_right,
			m_up,
			m_back,
			m_eye
		);

		return glm::inverse(view);
	}

	glm::mat4 Camera::GetProjMatrix()
	{
		float W = m_vpWidth;
		float H = m_vpHeight;
		float D = m_vpDist;

		float N = m_npDist;
		float F = m_fpDist;

		return {
			2.0f * D / W, 0, 0, 0,
			0, 2.0f * D / H, 0, 0,
			0, 0, (N + F) / (N - F), -1.0f,
			0, 0, (2.0f * N * F) / (N - F), 0
		};
	}

}