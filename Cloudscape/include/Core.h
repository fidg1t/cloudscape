#pragma once

#include <iostream>
#include <format>
#include <memory>
#include <vector>

// CLAPI Macro for Exporting Functions to DLL on Windows

#ifdef _WIN32
	#ifdef CL_ENGINE
		#define CLAPI __declspec(dllexport)
	#else
		#define CLAPI __declspec(dllimport)
	#endif
#else
	#define CLAPI
#endif

#include "Log.h"

// Logging
#define CL_INFO(...)		Cloudscape::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CL_WARN(...)		Cloudscape::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CL_ERROR(...)		Cloudscape::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CL_FATAL(...)		Cloudscape::Log::GetCoreLogger()->critical(__VA_ARGS__)

#ifdef _DEBUG
	#define CL_DEBUG(...)	Cloudscape::Log::GetCoreLogger()->debug(__VA_ARGS__)
#else
	#define CL_DEBUG(...)
#endif