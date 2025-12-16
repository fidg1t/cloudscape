#include "SandboxLayer.h"
#include "CLEngine.h"
#include "RenderSystem.h"

SandboxLayer::SandboxLayer() : cube(Cloudscape::CubeMesh())
{

}

SandboxLayer::~SandboxLayer()
{

}

void SandboxLayer::Update(float dt)
{

}

void SandboxLayer::Draw()
{
	cube.Draw();
}