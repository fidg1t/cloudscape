#include "CLEngine.h"
#include "EditorLayer.h"
#include "SandboxLayer.h"

int main()
{
	Cloudscape::CLEngineCFG eSpec;
	eSpec.window.title = "Nimbus";
	eSpec.window.width = 600;
	eSpec.window.height = 600;

	Cloudscape::CLEngine engine(eSpec);

	engine.AddLayer<SandboxLayer>();
	engine.AddLayer<EditorLayer>();

	engine.Run();
}