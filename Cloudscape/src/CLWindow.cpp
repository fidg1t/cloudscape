//-----------------------------------------------------------------------------
//
// File:    CLWindow.cpp
// Author:  Nicholas Brennan
// Purpose: Handles window creation and management
// 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "CLWindow.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_video.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

	CLWindow::CLWindow(const CLWindowCFG& cfg) : m_cfg(cfg), m_shouldClose(false)
	{
		m_handle = std::make_unique<CLWindowImpl>();
		m_handle->window = SDL_CreateWindow(m_cfg.title.c_str(), m_cfg.width, m_cfg.height, NULL);
	}

	CLWindow::~CLWindow()
	{
		if (m_handle.get())
		{
			SDL_DestroyWindow(m_handle->window);
		}
	}

	void CLWindow::Update(float dt)
	{
		SDL_Event event;
		CL_INFO(1 / dt);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
			{
				m_shouldClose = true;
			}
		}
	}

	bool CLWindow::ShouldClose() const
	{
		return m_shouldClose;
	}

}