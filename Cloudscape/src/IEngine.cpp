//-----------------------------------------------------------------------------
//
// File:    IEngine.cpp
// Author:  Nicholas Brennan
// Purpose: Function declarations for factory functions.
// 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "IEngine.h"
#include "Engine.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

  CLAPI IEngine* CreateEngine()
  {
    return new Engine();
  }

  CLAPI void DestroyEngine(IEngine* engine)
  {
    delete engine;
  }

}