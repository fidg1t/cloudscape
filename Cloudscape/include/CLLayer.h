#pragma once

#include "Core.h"

namespace Cloudscape {

  class CLAPI CLLayer
  {
  public:
    // For derived classes
    virtual ~CLLayer() = default;

    // Optional Implementations
    virtual void Load() {};
    virtual void Update(float dt) {};
    virtual void Draw() {};
    virtual void Unload() {};

  };

}