#ifdef CL_ENGINE
	#define CLAPI __declspec(dllexport)
#else
	#define CLAPI __declspec(dllimport)
#endif