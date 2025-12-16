#pragma once

#include "Core.h"

struct SDL_Window;

namespace Cloudscape {

	struct CLWindowCFG
	{
		int width = 900;
		int height = 600;
		std::string title = "Cloudscape Application";
	};

	struct CLWindowImpl
	{
		SDL_Window* window;
	};

	class CLAPI CLWindow
	{
	public:
		CLWindow(const CLWindowCFG& cfg = CLWindowCFG());
		~CLWindow();

		void Update(float dt);

		CLWindowImpl& GetWindowHandle() const;
		unsigned GetWidth() const;
		unsigned GetHeight() const;

		bool ShouldClose() const;


	private:
		CLWindowCFG m_cfg;
		unsigned m_width, m_height;

		bool m_shouldClose;


		std::unique_ptr<CLWindowImpl> m_handle;
	};

}