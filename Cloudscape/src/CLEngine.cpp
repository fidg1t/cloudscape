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
#include "RenderSystem.h"
#include "SDL3/SDL.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

  static CLEngine* s_Engine = nullptr;

  CLEngine::CLEngine(const CLEngineCFG& cfg) : m_cfg(cfg)
  {
    s_Engine = this;

    AddSystem<RenderSystem>(cfg.window);
  }

  CLEngine::~CLEngine()
  {
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

      Update(dt);
      Draw();

      if (GetSystem<RenderSystem>()->GetWindow().get()->ShouldClose()) 
        m_running = false;
    }

    Unload();
  }

  void CLEngine::Load()
  {
    for (auto& system : m_systems)
    {
      system->Load();
    }

    for (auto& layer : m_layers)
    {
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
      system->Unload();
    }

    for (auto& layer : m_layers)
    {
      layer->Unload();
    }
  }

  CLEngine& CLEngine::Get()
  {
    return *s_Engine;
  }
}