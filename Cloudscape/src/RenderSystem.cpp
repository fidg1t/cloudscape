//-----------------------------------------------------------------------------
//
// File:    RenderSystem.cpp
// Author:  Nicholas Brennan
// Purpose: Handles setup and management of graphics api (SDL3 + OpenGL)
// 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "RenderSystem.h"
#include "CLWindow.h"
#include "glad/glad.h"
#include "SDL3/SDL.h"
#include "glm/glm.hpp"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

	RenderSystem::RenderSystem(CLWindowCFG cfg)
	{
		CL_INFO("Render System Init");
		
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


		m_window = std::make_shared<CLWindow>(cfg);

		SDL_GLContext glContext = SDL_GL_CreateContext(m_window->GetWindowHandle().window);
		SDL_GL_MakeCurrent(m_window->GetWindowHandle().window, glContext);

		CL_INFO("GLAD Loaded");
		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			throw std::runtime_error("Failed to initialize GLAD");
		}
	}

	RenderSystem::~RenderSystem()
	{
		SDL_Quit();
		CL_INFO("Render System Exit");
	}

	void RenderSystem::Update(float dt)
	{
		m_window.get()->Update(dt);
	}

	void RenderSystem::Draw()
	{
		SDL_GL_SwapWindow(m_window->GetWindowHandle().window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	std::shared_ptr<CLWindow>& RenderSystem::GetWindow()
	{
		return m_window;
	}

	void RenderSystem::SetClearColor(glm::vec4 color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

}