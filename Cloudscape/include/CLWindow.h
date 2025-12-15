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

		bool ShouldClose() const;

	private:
		bool m_shouldClose;
		CLWindowCFG m_cfg;

		std::unique_ptr<CLWindowImpl> m_handle;
	};

}