#pragma once

#include "CLLayer.h"

class EditorLayer : public Cloudscape::CLLayer
{
public:
	EditorLayer();
	~EditorLayer();

	void Draw() override;

	void BeginUIFrame();
	void EndUIFrame();

private:
};