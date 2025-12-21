//-----------------------------------------------------------------------------
//
// File:    CLEngine.cpp
// Author:  Nicholas Brennan
// Purpose: Function declarations for factory functions.
// 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "CLEngine.h"
#include "SDL3/SDL.h"

#include "PlatformSystem.h"
#include "RenderSystem.h"
#include "EventSystem.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

  static CLEngine* s_Engine = nullptr;

  CLEngine::CLEngine(const CLEngineCFG& cfg) : m_cfg(cfg)
  {
    Log::Init();
    CL_INFO("Creating Engine");

    s_Engine = this;

    AddSystem<PlatformSystem>(cfg.window);
    AddSystem<RenderSystem>();
    //AddSystem<EventSystem>(m_layers);
  }

  CLEngine::~CLEngine()
  {
    CL_INFO("Destroying Engine");

    s_Engine = nullptr;
  }

  void CLEngine::Run()
  {
    Load();

    m_running = true;
    uint64_t lastTime = 0, currTime = SDL_GetPerformanceCounter();
    float dt = 0.0f;

    while (m_running)
    {
      lastTime = currTime;
      currTime = SDL_GetPerformanceCounter();

      dt = (currTime - lastTime) / (double)SDL_GetPerformanceFrequency();

      GetSystem<RenderSystem>()->BeginFrame();

      Update(dt);
      Draw();

      GetSystem<RenderSystem>()->EndFrame();


      if (GetSystem<PlatformSystem>()->GetWindow().get()->ShouldClose()) 
        m_running = false;
    }

    Unload();
  }

  void CLEngine::Load()
  {
    for (auto& system : m_systems)
    {
      CL_INFO("Loading system: {}", typeid(*system).name());
      system->Load();
    }

    for (auto& layer : m_layers)
    {
      CL_INFO("Loading layer: {}", typeid(*layer).name());
      layer->Load();
    }
  }

  void CLEngine::Update(float dt)
  {
    for (auto& system : m_systems)
    {
      system->Update(dt);
    }

    for (auto& layer : m_layers)
    {
      layer->Update(dt);
    }
  }

  void CLEngine::Draw()
  {
    for (auto& system : m_systems)
    {
      system->Draw();
    }

    for (auto& layer : m_layers)
    {
      layer->Draw();
    }
  }

  void CLEngine::Unload()
  {
    for (auto& system : m_systems)
    {
      CL_INFO("Unloading system: {}", typeid(*system).name());
      system->Unload();
    }

    for (auto& layer : m_layers)
    {
      CL_INFO("Unloading layer: {}", typeid(*layer).name());
      layer->Unload();
    }
  }

  CLEngine& CLEngine::Get()
  {
    return *s_Engine;
  }
}