#pragma once

#include "CLSystem.h"
#include "CLWindow.h"

namespace Cloudscape {

  class RenderSystem : public CLSystem
  {
  public:

    RenderSystem(CLWindowCFG cfg);
    ~RenderSystem();

    virtual void Update(float dt) override;

    std::shared_ptr<CLWindow>& GetWindow();

  private:
    std::shared_ptr<CLWindow> m_window;
  };

}