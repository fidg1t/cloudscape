#include "CLEngine.h"

int main()
{
	Cloudscape::CLEngineCFG eSpec;
	eSpec.window.title = "Nimbus";

	Cloudscape::CLEngine engine(eSpec);



	engine.Run();
}