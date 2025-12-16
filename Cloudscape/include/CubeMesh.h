#pragma once

#include "glad/glad.h"
#include "Core.h"

namespace Cloudscape {

	class CLAPI CubeMesh
	{
	public:
		CubeMesh();
		~CubeMesh() = default;

		void Draw();
	private:
		GLuint vbo, ebo, vao;
		GLuint fragShader, vertShader, program;
	};

}

