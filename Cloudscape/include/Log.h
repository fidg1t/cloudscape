#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>

namespace Cloudscape {

	class CLAPI Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		static std::shared_ptr<spdlog::logger>& GetClientLogger();

	private:
		static std::shared_ptr<spdlog::logger> s_engineLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};

}