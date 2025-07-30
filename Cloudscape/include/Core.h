#ifdef ENGINE_EXPORTS
	#define CLAPI __declspec(dllexport)
#else
	#define CLAPI __declspec(dllimport)
#endif