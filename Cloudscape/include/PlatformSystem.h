#pragma once

#include "CLSystem.h"
#include "CLWindow.h"

namespace Cloudscape {

  class PlatformSystem : public CLSystem
  {
  public:

    PlatformSystem(CLWindowCFG cfg);
    ~PlatformSystem();

    virtual void Update(float dt) override;

    std::shared_ptr<CLWindow>& GetWindow();

  private:
    std::shared_ptr<CLWindow> m_window;
  };

}