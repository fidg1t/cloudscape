#include "SandboxLayer.h"
#include "CLEngine.h"
#include "RenderSystem.h"

SandboxLayer::SandboxLayer() : timer(0.0f)
{
	
}

SandboxLayer::~SandboxLayer()
{

}

void SandboxLayer::Update(float dt)
{
	timer += dt;
	color.r = 0.5f + 0.5f * sinf(timer + 0.0f);
	color.g = 0.5f + 0.5f * sinf(timer + 2.0f);
	color.b = 0.5f + 0.5f * sinf(timer + 4.0f);
	color.a = 1.0f;
}

void SandboxLayer::Draw()
{
	Cloudscape::CLEngine::Get().GetSystem<Cloudscape::RenderSystem>()->SetClearColor(color);
}