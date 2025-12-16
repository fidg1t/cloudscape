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
#include "CLLayer.h"
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
    void AddSystem(Args&&... args)
    {
      m_systems.push_back(std::make_unique<TSystem>(std::forward<Args>(args)...));
    }

    template <typename TSystem>
    requires(std::is_base_of_v<CLSystem, TSystem>)
    TSystem* GetSystem()
    {
      for (const auto& system : m_systems)
      {
        if (auto foundSystem = dynamic_cast<TSystem*>(system.get()))
          return foundSystem;
      }
      return nullptr;
    }


    template <typename TLayer, typename... Args>
    requires(std::is_base_of_v<CLLayer, TLayer>)
    void AddLayer(Args&&... args)
    {
      m_layers.push_back(std::make_unique<TLayer>(std::forward<Args>(args)...));
    }

    template <typename TLayer>
    requires(std::is_base_of_v<CLLayer, TLayer>)
    TLayer* GetLayer()
    {
      for (const auto& layer : m_layers)
      {
        if (auto foundLayer = dynamic_cast<TLayer*>(layer.get()))
          return foundLayer;
      }
      return nullptr;
    }


    static CLEngine& Get();

  private:
    bool m_running = false;
    CLEngineCFG m_cfg;

    std::vector<std::unique_ptr<CLSystem>> m_systems;
    std::vector<std::unique_ptr<CLLayer>> m_layers;
  };
}