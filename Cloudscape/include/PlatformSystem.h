#pragma once

#include "CLSystem.h"
#include "CLWindow.h"
#include "SDL3/SDL.h"

namespace Cloudscape {

  class CLAPI PlatformSystem : public CLSystem
  {
  public:

    PlatformSystem(CLWindowCFG cfg);
    ~PlatformSystem();

    void Update(float dt) override;
    void Draw() override;

    void SwapBuffers();

    std::shared_ptr<CLWindow>& GetWindow();

  private:
    SDL_GLContext m_glContext;

    std::shared_ptr<CLWindow> m_window;
  };

}