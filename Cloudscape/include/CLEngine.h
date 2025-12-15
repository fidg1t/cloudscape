//-----------------------------------------------------------------------------
//
// File:    CLEngine.h
// Author:  Nicholas Brennan
// Purpose: Interface class for Engine. This is called by client application
//          outside of shared library.
// 
//-----------------------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "CLSystem.h"
#include "CLWindow.h"
#include "Core.h"

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------

namespace Cloudscape {

  struct CLEngineCFG
  {
    CLWindowCFG window;
  };

  class CLAPI CLEngine
  {
  public:
    CLEngine(const CLEngineCFG& cfg = CLEngineCFG());
    ~CLEngine();

    CLEngine(const CLEngine&) = delete;
    CLEngine& operator=(const CLEngine&) = delete;

    void Run();

    void Load();
    void Update(float dt);
    void Draw();
    void Unload();

    template <typename TSystem, typename... Args>
    requires(std::is_base_of_v<CLSystem, TSystem>)
    void AddSystem(Args&&... args);

    template <typename TSystem>
    requires(std::is_base_of_v<CLSystem, TSystem>)
    TSystem* GetSystem();

    CLEngine& Get();

  private:
    bool m_running = false;
    CLEngineCFG m_cfg;

    std::vector<std::unique_ptr<CLSystem>> m_systems;
  };
}