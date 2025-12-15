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
#include "SDL3/SDL.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

	PlatformSystem::PlatformSystem(CLWindowCFG cfg)
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
		CL_INFO("Platform System Init");

		m_window = std::make_shared<CLWindow>(cfg);
	}

	PlatformSystem::~PlatformSystem()
	{
		SDL_Quit();
		CL_INFO("Platform System Exit");
	}

	void PlatformSystem::Update(float dt)
	{
		m_window.get()->Update(dt);
	}

	std::shared_ptr<CLWindow>& PlatformSystem::GetWindow()
	{
		return m_window;
	}

}