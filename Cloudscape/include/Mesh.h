#pragma once

#include "Core.h"
#include "glad/glad.h"
#include "glm/glm.hpp"

namespace Cloudscape {

	namespace Lightning {
	
		struct CLAPI Vertex
		{
			glm::vec3 vert;
			glm::vec3 norm;
			glm::vec2 uv;
		};

		class CLAPI Mesh
		{
		public:
			Mesh(const std::vector<Vertex>& vertices,
					 const std::vector<GLuint>& indices);

			~Mesh();

			void Draw();
			
			void Bind() const;
			void Unbind() const;

			size_t GetVertexCount() const;
			size_t GetIndexCount() const;

		private:
			std::vector<Vertex> m_vertices;
			std::vector<GLuint> m_indices;

			GLuint m_vbo, m_ebo, m_vao;
		};

	}

}