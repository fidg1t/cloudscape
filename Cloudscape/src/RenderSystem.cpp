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
#include "SDL3/SDL.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

	RenderSystem::RenderSystem(CLWindowCFG cfg)
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
		CL_INFO("Render System Init");

		m_window = std::make_shared<CLWindow>(cfg);
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

	std::shared_ptr<CLWindow>& RenderSystem::GetWindow()
	{
		return m_window;
	}

}