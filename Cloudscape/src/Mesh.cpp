#include "Mesh.h"
#include <fstream>
#include <sstream>
#include <filesystem>

namespace Cloudscape {

	namespace Lightning {
	
		Mesh::Mesh()
    {
      std::ifstream file("shader/default.vert", std::ios::in);
      std::stringstream buffer;
      buffer << file.rdbuf();
      std::string source = buffer.str();
      const char* vertShaderSource = source.c_str();

      std::cout << std::filesystem::current_path() << std::endl;

      vertShader = glCreateShader(GL_VERTEX_SHADER);
      glShaderSource(vertShader, 1, &vertShaderSource, nullptr);
      glCompileShader(vertShader);

      GLint success = 0;
      glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
      if (!success)
      {
        char infoLog[1024];
        glGetShaderInfoLog(vertShader, sizeof(infoLog), nullptr, infoLog);
        CL_ERROR("Vertex shader compile error:\n" + std::string(infoLog));
        assert(0);
      }

      buffer.str("");
      buffer.clear();
      file = std::ifstream("shader/default.frag");
      buffer << file.rdbuf();
      source = buffer.str();
      const char* fragShaderSource = source.c_str();

      fragShader = glCreateShader(GL_FRAGMENT_SHADER);
      glShaderSource(fragShader, 1, &fragShaderSource, nullptr);
      glCompileShader(fragShader);

      glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
      if (!success)
      {
        char infoLog[1024];
        glGetShaderInfoLog(fragShader, sizeof(infoLog), nullptr, infoLog);
        CL_ERROR("Fragment shader compile error:\n" + std::string(infoLog));
        assert(0);
      }

      program = glCreateProgram();
      glAttachShader(program, vertShader);
      glAttachShader(program, fragShader);
      glLinkProgram(program);

      glGetProgramiv(program, GL_LINK_STATUS, &success);
      if (!success)
      {
        char infoLog[1024];
        glGetProgramInfoLog(program, sizeof(infoLog), nullptr, infoLog);
        CL_ERROR("Shader link error:\n" + std::string(infoLog));
        assert(0);
      }

      glDeleteShader(vertShader);
      glDeleteShader(fragShader);


      glGenVertexArrays(1, &vao);
      glGenBuffers(1, &vbo);
      glGenBuffers(1, &ebo);

      glBindVertexArray(vao);

      glBindBuffer(GL_ARRAY_BUFFER, vbo);
      glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices.data(), GL_STATIC_DRAW);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices.data(), GL_STATIC_DRAW);

      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, vert));
      glEnableVertexAttribArray(0);

      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, norm));
      glEnableVertexAttribArray(1);

      glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
      glEnableVertexAttribArray(2);

      glBindVertexArray(0);
    }

		Mesh::~Mesh()
		{

		}



	}

}