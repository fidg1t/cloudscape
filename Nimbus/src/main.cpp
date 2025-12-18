#include "CLEngine.h"
#include "SandboxLayer.h"

int main()
{
	Cloudscape::CLEngineCFG eSpec;
	eSpec.window.title = "Nimbus";
	eSpec.window.width = 600;
	eSpec.window.height = 600;

	Cloudscape::CLEngine engine(eSpec);

	engine.AddLayer<SandboxLayer>();

	engine.Run();
}