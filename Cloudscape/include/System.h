#pragma once

#include "Core.h"

namespace Cloudscape {

  class CLAPI System
  {
  public:
    // For derived classes
    virtual ~System() = default;

    // Pure virtual
    virtual void Init() = 0;
    virtual void Load() = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw() = 0;
    virtual void Unload() = 0;
    virtual void Exit() = 0;
 
  };

}