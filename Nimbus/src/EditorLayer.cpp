#include "EditorLayer.h"
#include "CLEngine.h"
#include "PlatformSystem.h"
#include "CLWindow.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_opengl3.h"
#include "SDL3/SDL.h"

EditorLayer::EditorLayer()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	auto window = Cloudscape::CLEngine::Get()
		.GetSystem<Cloudscape::PlatformSystem>()
		->GetWindow()
		->GetWindowHandle().window;

	ImGui_ImplSDL3_InitForOpenGL(window, SDL_GL_GetCurrentContext());
	ImGui_ImplOpenGL3_Init("#version 460");
}

EditorLayer::~EditorLayer()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();
}

void EditorLayer::Draw()
{
	BeginUIFrame();

	// Put All Editor Code Here

	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Create"))
			{

			}
			if (ImGui::MenuItem("Open"))
			{

			}
			if (ImGui::MenuItem("Save"))
			{

			}
			if (ImGui::MenuItem("Save as..."))
			{

			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	// End

	EndUIFrame();
}

void EditorLayer::BeginUIFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL3_NewFrame();
	ImGui::NewFrame();
}

void EditorLayer::EndUIFrame()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}