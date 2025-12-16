//-----------------------------------------------------------------------------
//
// File:    PlatformSystem.cpp
// Author:  Nicholas Brennan
// Purpose: Handles setup and management of graphics api (SDL3 + OpenGL)
// 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "PlatformSystem.h"
#include "CLWindow.h"
#include "glad/glad.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

	PlatformSystem::PlatformSystem(CLWindowCFG cfg)
	{
		CL_INFO("Render System Init");
		
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		m_window = std::make_shared<CLWindow>(cfg);

		m_glContext = SDL_GL_CreateContext(m_window->GetWindowHandle().window);
		SDL_GL_MakeCurrent(m_window->GetWindowHandle().window, m_glContext);

		CL_INFO("GLAD Loaded");
		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			throw std::runtime_error("Failed to initialize GLAD");
		}

		glViewport(0, 0, m_window->GetWidth(), m_window->GetHeight());
	}

	PlatformSystem::~PlatformSystem()
	{
		CL_INFO("Render System Exit");
		SDL_GL_DestroyContext(m_glContext);
		SDL_Quit();
	}

	void PlatformSystem::Update(float dt)
	{
		m_window->Update(dt);
	}

	void PlatformSystem::Draw()
	{
		SwapBuffers();
	}

	void PlatformSystem::SwapBuffers()
	{
		SDL_GL_SwapWindow(m_window->GetWindowHandle().window);
	}

	std::shared_ptr<CLWindow>& PlatformSystem::GetWindow()
	{
		return m_window;
	}

}