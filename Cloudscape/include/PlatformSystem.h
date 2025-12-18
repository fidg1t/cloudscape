#pragma once

#include "CLSystem.h"
#include "CLWindow.h"

namespace Cloudscape {

  class CLAPI PlatformSystem : public CLSystem
  {
  public:

    PlatformSystem(CLWindowCFG cfg);
    ~PlatformSystem();

    void Update(float dt) override;
    void Draw() override;

    void SwapBuffers();
    void ResizeCallback();

    std::shared_ptr<CLWindow>& GetWindow();

  private:
    struct RenderImpl;

    std::unique_ptr<RenderImpl> m_impl;

    std::shared_ptr<CLWindow> m_window;
  };

}