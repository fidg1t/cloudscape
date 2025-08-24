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
#include "CLEngine.h"

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------

namespace Cloudscape {

  class CLSystem;

  class Engine : public CLEngine
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

    void AddSystem(CLSystem* system) override;

  private:
    std::vector<CLSystem*> m_systems;
  };

}