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
  }

  void CLEngine::Update(float dt)
  {
    for (auto& system : m_systems)
    {
      system->Update(dt);
    }
  }

  void CLEngine::Draw()
  {
    for (auto& system : m_systems)
    {
      system->Draw();
    }
  }

  void CLEngine::Unload()
  {
    for (auto& system : m_systems)
    {
      system->Unload();
    }
  }

  template <typename TSystem, typename... Args>
  requires(std::is_base_of_v<CLSystem, TSystem>)
  void CLEngine::AddSystem(Args&&... args)
  {
    m_systems.push_back(std::make_unique<TSystem>(std::forward<Args>(args)...));
  }

  template <typename TSystem>
  requires(std::is_base_of_v<CLSystem, TSystem>)
  TSystem* CLEngine::GetSystem()
  {
    for (const auto& system : m_systems)
    {
      if (auto foundSystem = dynamic_cast<TSystem*>(system.get()))
        return foundSystem;
    }
    return nullptr;
  }

  template <typename TLayer, typename... Args>
  requires(std::is_base_of_v<CLSystem, TLayer>)
  void CLEngine::AddLayer(Args&&... args)
  {
    m_systems.push_back(std::make_unique<TLayer>(std::forward<Args>(args)...));
  }

  template <typename TLayer>
  requires(std::is_base_of_v<CLSystem, TLayer>)
  TLayer* CLEngine::GetLayer()
  {
    for (const auto& layer : m_layers)
    {
      if (auto foundLayer = dynamic_cast<TLayer*>(layer.get()))
        return foundLayer;
    }
    return nullptr;
  }

  CLEngine& CLEngine::Get()
  {
    return *s_Engine;
  }
}