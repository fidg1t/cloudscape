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
#include "CLEngine.h"
#include "RenderSystem.h"
#include "glad/glad.h"
#include "SDL3/SDL.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

	struct PlatformSystem::RenderImpl
	{
		SDL_GLContext glContext = nullptr;
	};

	PlatformSystem::PlatformSystem(CLWindowCFG cfg) : m_impl(std::make_unique<RenderImpl>())
	{	
		// SDL Init
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

		// OpenGL Init
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		// Make Window
		m_window = std::make_shared<CLWindow>(cfg);

		m_impl->glContext = SDL_GL_CreateContext(m_window->GetWindowHandle().window);
		SDL_GL_MakeCurrent(m_window->GetWindowHandle().window, m_impl->glContext);

		CL_INFO("GLAD Loaded");
		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			CL_FATAL("Failed to initialize GLAD");
			throw std::runtime_error("Failed to initalize GLAD");
		}

		glViewport(0, 0, m_window->GetWidth(), m_window->GetHeight());
	}

	PlatformSystem::~PlatformSystem()
	{
		SDL_GL_DestroyContext(m_impl->glContext);
		SDL_Quit();
	}

	void PlatformSystem::Update(float dt)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
				m_window->RequestClose();
				break;

			case SDL_EVENT_WINDOW_RESIZED:
				unsigned width = event.window.data1;
				unsigned height = event.window.data2;

				m_window->RequestResize(width, height);
				CLEngine::Get().GetSystem<RenderSystem>()->OnResize(width, height);
				break;
			}
		}
	}

	void PlatformSystem::Draw()
	{

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