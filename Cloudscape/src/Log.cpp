#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Cloudscape {

	std::shared_ptr<spdlog::logger> Log::s_engineLogger;
	std::shared_ptr<spdlog::logger> Log::s_clientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_engineLogger = spdlog::stdout_color_mt("CLOUDSCAPE");
		s_engineLogger->set_level(spdlog::level::trace);

		s_clientLogger = spdlog::stdout_color_mt("GAME");
		s_clientLogger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
	{
		return s_engineLogger;
	}

	std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
	{
		return s_clientLogger;
	}

}