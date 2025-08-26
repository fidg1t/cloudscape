//-----------------------------------------------------------------------------
//
// File:    CLEngine.cpp
// Author:  Nicholas Brennan
// Purpose: Function declarations for factory functions.
// 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "CLEngine.h"
#include "Engine.h"
#include "SDL3/SDL.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

  void CLEngine::Run()
  {
    Init();
    Load();

    bool running = true;
    uint64_t lastTime = 0, currTime = SDL_GetTicks();
    float dt = 0.0f;

    while (running)
    {
      lastTime = currTime;
      currTime = SDL_GetTicks();

      dt = (float)((currTime - lastTime) * 1000 / (float)SDL_GetPerformanceFrequency());

      Update(dt);
      Draw();

      if (m_shouldExit) running = false;
    }

    Unload();
    Exit();
  }

  CLAPI CLEngine* CreateEngine()
  {
    return new Engine();
  }

  CLAPI void DestroyEngine(CLEngine* engine)
  {
    delete engine;
  }

}