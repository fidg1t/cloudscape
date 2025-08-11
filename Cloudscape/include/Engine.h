//-----------------------------------------------------------------------------
//
// File:    Engine.h
// Author:  Nicholas Brennan
// Purpose: Private implementation of Engine, hidden from client applications.
// 
//-----------------------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <vector>
#include "Core.h"
#include "IEngine.h"

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------

namespace Cloudscape {

  class System;

  class Engine : public IEngine
  {
  public:
    Engine() = default;
    ~Engine() = default;

    void Init() override;
    void Load() override;
    void Update(float dt) override;
    void Draw() override;
    void Unload() override;
    void Exit() override;

    void AddSystem(System* system) override;

  private:
    std::vector<System*> m_systems;
  };

}