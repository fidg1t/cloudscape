#include "CLEngine.h"
#include <iostream>

int main()
{
	Cloudscape::CLEngineCFG eSpec;
	eSpec.window.title = "Nimbus";

	Cloudscape::CLEngine engine(eSpec);
	engine.Run();
}