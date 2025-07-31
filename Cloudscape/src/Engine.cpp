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
#include "System.h"
#include <iostream>

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

  void Engine::Init()
  {
    for (auto system : m_systems)
    {
      system->Init();
    }
  }

  void Engine::Load()
  {
    for (auto system : m_systems)
    {
      system->Load();
    }
  }

  void Engine::Update(float dt)
  {
    for (auto system : m_systems)
    {
      system->Update(dt);
    }
  }

  void Engine::Draw()
  {
    for (auto system : m_systems)
    {
      system->Draw();
    }
  }

  void Engine::Unload()
  {
    for (auto system : m_systems)
    {
      system->Unload();
    }
  }

  void Engine::Exit()
  {
    for (auto system : m_systems)
    {
      system->Exit();
    }
  }

  void Engine::AddSystem(System* system)
  {
    m_systems.push_back(system);
  }

}