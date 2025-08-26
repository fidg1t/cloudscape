#pragma once

#include <iostream>

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

///TODO: Add spdlog to project and replace these!
// Logging
#define CL_INFO(X)		std::cout << std::format("INFO: {}\n", x)
#define CL_ERROR(x)		std::cout << std::format("ERROR: {}\n", x)

#ifdef _DEBUG
	#define CL_DEBUG(x) std::cout << std::format("DEBUG: {}\n", x)
#else
	#define CL_DEBUG(x)
#endif