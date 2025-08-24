//-----------------------------------------------------------------------------
//
// File:    CLEngine.h
// Author:  Nicholas Brennan
// Purpose: Interface class for Engine. This is called by client application
//          outside of shared library.
// 
//-----------------------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <vector>
#include "Core.h"

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------

namespace Cloudscape {

  class CLSystem;
   
  class CLAPI CLEngine
  {
  public:
    virtual ~CLEngine() = default;

    virtual void Init() = 0;
    virtual void Load() = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw() = 0;
    virtual void Unload() = 0;
    virtual void Exit() = 0;

    virtual void AddSystem(CLSystem* system) = 0;
  };

  // Factory Functions
  CLAPI CLEngine* CreateEngine();
  CLAPI void DestroyEngine(CLEngine* engine);

}