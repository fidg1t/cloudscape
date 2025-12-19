#include "Transform.h"
#include "glm/gtc/matrix_transform.hpp"

namespace Cloudscape {

	Transform::Transform(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation)
		: m_pos(pos), m_scale(scale), m_rotation(rotation)
	{
		
	}

	Transform::~Transform()
	{

	}

	void Transform::SetPosition(glm::vec3 position)
	{
		m_pos = position;
	}

	void Transform::SetScale(glm::vec3 scale)
	{
		m_scale = scale;
	}

	void Transform::SetRotation(glm::vec3 rotation)
	{
		m_rotation = rotation;
	}

	glm::vec3 Transform::GetPosition() const
	{
		return m_pos;
	}

	glm::vec3 Transform::GetScale() const
	{
		return m_scale;
	}

	glm::vec3 Transform::GetRotation() const
	{
		return m_rotation;
	}

	glm::mat4 Transform::GetModelingTransform() const
	{
		glm::mat4 T = glm::translate(glm::mat4(1.0f), m_pos);
		glm::mat4 S = glm::scale(glm::mat4(1.0f), m_scale);

		glm::mat4 Rx = glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation.x),
			glm::vec3(1, 0, 0));
		glm::mat4 Ry = glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation.y),
			glm::vec3(0, 1, 0));
		glm::mat4 Rz = glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation.z),
			glm::vec3(0, 0, 1));

		glm::mat4 R = Rz * Ry * Rx;

		return  T * S * R;
	}

}