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
#include <memory>
#include "Core.h"
#include "CLEngine.h"
#include "CLSystem.h"

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------

namespace Cloudscape {

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
    std::vector<std::unique_ptr<CLSystem>> m_systems;
  };

}