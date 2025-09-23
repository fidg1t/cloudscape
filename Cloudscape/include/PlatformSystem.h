#pragma once

#include "CLSystem.h"
#include "CLWindow.h"

namespace Cloudscape {

  class PlatformSystem : public CLSystem
  {
  public:

    PlatformSystem() = default;
    ~PlatformSystem() = default;

    virtual void Init() override;
    virtual void Update(float dt) override;
    virtual void Exit() override;

    std::unique_ptr<CLWindow>& GetWindow();

  private:
    std::unique_ptr<CLWindow> m_window;
  };

}