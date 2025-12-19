#pragma once

#include "Core.h"
#include "glm/glm.hpp"
#include "glad/glad.h"

namespace Cloudscape::Lightning {

	class CLAPI Shader
	{
	public:
		Shader(const std::string& vertexShaderPath, 
					 const std::string& fragmentShaderPath);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void SetVec3(std::string name, glm::vec3 vec);
		void SetMat4(std::string name, glm::mat4 mat);
	private:
		GLuint m_program;

		std::string LoadFile(const std::string& path);
		GLuint CompileShader(const std::string& source, GLenum type);
	};

}