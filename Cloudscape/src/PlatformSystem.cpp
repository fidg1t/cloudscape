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
#include "SDL3/SDL.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

	void PlatformSystem::Init()
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
		CL_INFO("Platform System Init");
	}

	void PlatformSystem::Update(float dt)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			dt += 1.f;
		}
	}

	void PlatformSystem::Exit()
	{
		SDL_Quit();
		CL_INFO("Platform System Exit");
	}

}