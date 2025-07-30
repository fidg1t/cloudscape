#pragma once

#include <vector>

#include "Core.h"
#include "System.h"

namespace Cloudscape {

  class CLAPI Engine
  {
  public:
    Engine() = default;
    ~Engine() = default;

    void Init();
    void Load();
    void Update(float dt);
    void Draw();
    void Unload();
    void Exit();

  private:
    std::vector<System*> m_systems;
  };

}