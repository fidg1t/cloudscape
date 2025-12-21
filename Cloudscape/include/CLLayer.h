#pragma once

#include "Core.h"
#include "Event.h"

namespace Cloudscape {

  class CLAPI CLLayer
  {
  public:
    // For derived classes
    virtual ~CLLayer() = default;

    // Optional Implementations
    virtual void OnEvent(Event& event) {}
    
    virtual void Load() {}
    virtual void Update(float dt) {}
    virtual void Draw() {}
    virtual void Unload() {}

  };

}