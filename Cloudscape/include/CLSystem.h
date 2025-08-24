#pragma once

#include "Core.h"

namespace Cloudscape {

  class CLAPI CLSystem
  {
  public:
    // For derived classes
    virtual ~CLSystem() = default;

    // Required Implementations
    virtual void Init() = 0;
    virtual void Update(float dt) = 0;
    virtual void Exit() = 0;

    // Optional Implementations
    virtual void Load() {};
    virtual void Draw() {};
    virtual void Unload() {};
 
  };

}