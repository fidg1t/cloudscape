#include "Mesh.h"
#include <fstream>
#include <sstream>
#include <filesystem>

namespace Cloudscape {

	namespace Lightning {
	
		Mesh::Mesh(const std::vector<Vertex>& vertices,
               const std::vector<GLuint>& indices)
      : m_vertices(vertices), m_indices(indices)
    {
      glGenVertexArrays(1, &m_vao);
      glGenBuffers(1, &m_vbo);
      glGenBuffers(1, &m_ebo);

      glBindVertexArray(m_vao);

      glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
      glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_STATIC_DRAW);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(GLuint), m_indices.data(), GL_STATIC_DRAW);

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
      glDeleteVertexArrays(1, &m_vao);
      glDeleteBuffers(1, &m_vbo);
      glDeleteBuffers(1, &m_ebo);
		}

    void Mesh::Draw()
    {
      glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, nullptr);
    }

    void Mesh::Bind() const
    {
      glBindVertexArray(m_vao);
    }

    void Mesh::Unbind() const
    {
      glBindVertexArray(0);
    }

    size_t Mesh::GetVertexCount() const
    {
      return m_vertices.size();
    }

    size_t Mesh::GetIndexCount() const
    {
      return m_indices.size();
    }

	}

}