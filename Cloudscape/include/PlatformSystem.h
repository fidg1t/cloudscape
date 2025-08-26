#pragma once

#include "CLSystem.h"

namespace Cloudscape {

  class PlatformSystem : public CLSystem
  {
  public:

    PlatformSystem() = default;
    ~PlatformSystem() = default;

    virtual void Init() override;
    virtual void Update(float dt) override;
    virtual void Exit() override;

  };

}