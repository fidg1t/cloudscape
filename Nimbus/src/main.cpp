#include "CLEngine.h"
#include "SandboxLayer.h"

int main()
{
	Cloudscape::CLEngineCFG eSpec;
	eSpec.window.title = "Nimbus";

	Cloudscape::CLEngine engine(eSpec);

	engine.AddLayer<SandboxLayer>();

	engine.Run();
}