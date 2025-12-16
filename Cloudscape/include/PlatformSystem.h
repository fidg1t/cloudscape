#pragma once

#include "CLSystem.h"
#include "CLWindow.h"
#include "glm/glm.hpp"

namespace Cloudscape {

  class CLAPI PlatformSystem : public CLSystem
  {
  public:

    PlatformSystem(CLWindowCFG cfg);
    ~PlatformSystem();

    virtual void Update(float dt) override;
    virtual void Draw() override;

    std::shared_ptr<CLWindow>& GetWindow();

    void SetClearColor(glm::vec4 color);

  private:
    std::shared_ptr<CLWindow> m_window;
  };

}