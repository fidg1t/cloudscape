#include "Camera.h"
#include "CLWindow.h"
#include "glm/gtc/matrix_transform.hpp"

namespace Cloudscape::Lightning {

	//TEMPORARY!! construct this better
	Camera::Camera(float fov, float aspect)
	{
		m_right = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
		m_up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
		m_back = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
		m_eye = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

		m_aspect = aspect;
		m_fov = fov;

		m_np = 0.1f;
		m_fp = 10.0f;
	}

	Camera::~Camera()
	{
	
	}


	glm::mat4 Camera::LookAt(glm::vec3 lookPoint)
	{
		return glm::lookAt(glm::vec3(m_eye), lookPoint, glm::vec3(m_up));
	}

	void Camera::SetViewport(unsigned width, unsigned height)
	{
		m_aspect = static_cast<float>(width) / static_cast<float>(height);
	}

	void Camera::SetPosition(glm::vec3 pos)
	{
		m_eye = glm::vec4(pos, 1.0f);
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

	glm::vec3 Camera::GetPosition()
	{
		return glm::vec3(m_eye);
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
		return glm::perspective(m_fov, m_aspect, m_np, m_fp);
	}

}