#pragma once

#include "Core.h"

namespace Cloudscape {

  class CLAPI CLSystem
  {
  public:
    // For derived classes
    CLSystem() {};
    virtual ~CLSystem() = default;

    // Optional Implementations
    virtual void Load() {};
    virtual void Update(float dt) {};
    virtual void Draw() {};
    virtual void Unload() {};
 
  };

}