#pragma once

#include "Core.h"
#include "glad/glad.h"
#include "glm/glm.hpp"

namespace Cloudscape {

	namespace Lightning {
	
		struct Vertex
		{
			glm::vec3 vert;
			glm::vec3 norm;
			glm::vec2 uv;
		};

		class CLAPI Mesh
		{
		public:
			Mesh();
			~Mesh();

			void Draw();
		private:
			std::vector<Vertex> m_vertices;
			std::vector<GLuint> m_indices;

			GLuint vbo, ebo, vao;
			GLuint fragShader, vertShader, program;
		};

	}

}