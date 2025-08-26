//-----------------------------------------------------------------------------
//
// File:    Engine.cpp
// Author:  Nicholas Brennan
// Purpose: Interface class for Engine. This is called by client application
//          outside of shared library.
// 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "Engine.h"
#include "CLSystem.h"
#include "PlatformSystem.h"
#include <iostream>

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

  Engine::Engine()
  {
    AddSystem(std::make_unique<PlatformSystem>());
  }

  void Engine::Init()
  {
    for (auto& system : m_systems)
    {
      system->Init();
    }
  }

  void Engine::Load()
  {
    for (auto& system : m_systems)
    {
      system->Load();
    }
  }

  void Engine::Update(float dt)
  {
    for (auto& system : m_systems)
    {
      system->Update(dt);
    }
  }

  void Engine::Draw()
  {
    for (auto& system : m_systems)
    {
      system->Draw();
    }
  }

  void Engine::Unload()
  {
    for (auto& system : m_systems)
    {
      system->Unload();
    }
  }

  void Engine::Exit()
  {
    for (auto& system : m_systems)
    {
      system->Exit();
    }
  }

  void Engine::AddSystem(std::unique_ptr<CLSystem> system)
  {
    m_systems.push_back(std::move(system));
  }
}