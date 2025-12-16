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

	CLWindow::CLWindow(const CLWindowCFG& cfg) 
		: m_cfg(cfg), m_shouldClose(false), m_width(cfg.width), m_height(cfg.height)
	{
		m_handle = std::make_unique<CLWindowImpl>();
		m_handle->window = SDL_CreateWindow(m_cfg.title.c_str(), m_cfg.width, m_cfg.height, SDL_WINDOW_OPENGL);
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

	CLWindowImpl& CLWindow::GetWindowHandle() const
	{
		return *m_handle;
	}

	unsigned CLWindow::GetWidth() const
	{
		return m_width;
	}

	unsigned CLWindow::GetHeight() const
	{
		return m_height;
	}

	bool CLWindow::ShouldClose() const
	{
		return m_shouldClose;
	}

}