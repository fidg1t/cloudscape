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
		m_handle->window = SDL_CreateWindow(m_cfg.title.c_str(), m_cfg.width, m_cfg.height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
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
		
	}

	void CLWindow::RequestClose()
	{
		m_shouldClose = true;
	}

	void CLWindow::RequestResize(unsigned width, unsigned height)
	{
		m_width = width;
		m_height = height;

		
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