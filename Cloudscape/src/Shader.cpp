#include "Shader.h"
#include <fstream>
#include <sstream>

namespace Cloudscape::Lightning {

	Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
	{
		std::string vertexShaderSource = LoadFile(vertexShaderPath);
		std::string fragmentShaderSource = LoadFile(fragmentShaderPath);

		GLuint vertShader = CompileShader(vertexShaderSource, GL_VERTEX_SHADER);
		GLuint fragShader = CompileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

		m_program = glCreateProgram();

		glAttachShader(m_program, vertShader);
		glAttachShader(m_program, fragShader);

		glLinkProgram(m_program);

		GLint success = 0;
		glGetProgramiv(m_program, GL_LINK_STATUS, &success);
		if (!success)
		{
			char infoLog[1024];
			glGetProgramInfoLog(m_program, sizeof(infoLog), nullptr, infoLog);
			CL_ERROR("Shader compile error:\n" + std::string(infoLog));
		}

		glDeleteShader(vertShader);
		glDeleteShader(fragShader);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_program);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_program);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::SetVec3(std::string name, glm::vec3 vec)
	{
		GLint loc = glGetUniformLocation(m_program, name.c_str());
		glUniform3fv(loc, 1, &vec[0]);
	}

	void Shader::SetMat4(std::string name, glm::mat4 mat)
	{
		GLint loc = glGetUniformLocation(m_program, name.c_str());
		glUniformMatrix4fv(loc, 1, GL_FALSE, &mat[0][0]);
	}

	std::string Shader::LoadFile(const std::string& path)
	{
		CL_INFO("Loading File: {}", path);
		std::ifstream file(path);

		if (!file.is_open())
		{
			CL_FATAL("Failed to open shader file {}", path);
			throw std::runtime_error("Failed to open shader file: " + path);
		}

		std::stringstream buffer;
		buffer << file.rdbuf();
		return buffer.str();
	}

	GLuint Shader::CompileShader(const std::string& source, GLenum type)
	{
		GLuint shader = glCreateShader(type);
		const char* src = source.c_str();

		glShaderSource(shader, 1, &src, nullptr);
		glCompileShader(shader);


		GLint success = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char infoLog[1024];
			glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
			switch (type)
			{
			case GL_VERTEX_SHADER:
				CL_ERROR("Vertex Shader compile error:\n" + std::string(infoLog));
				break;
			case GL_FRAGMENT_SHADER:
				CL_ERROR("Fragment Shader compile error:\n" + std::string(infoLog));
				break;
			}
			CL_WARN("Shader Compilation Failed. Engine will continue to run, but graphical problems may ensue.");
		}

		return shader;
	}
}