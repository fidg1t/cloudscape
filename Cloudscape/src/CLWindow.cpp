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
#include "SDL3/SDL_video.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

	CLWindow::CLWindow()
	{
		m_cfg = CLWindowCFG();
		m_handle = std::make_unique<CLWindowImpl>();
		m_handle->window = SDL_CreateWindow(m_cfg.title.c_str(), m_cfg.width, m_cfg.height, NULL);
	}

	CLWindow::CLWindow(const CLWindowCFG& cfg) : m_cfg(cfg)
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

}