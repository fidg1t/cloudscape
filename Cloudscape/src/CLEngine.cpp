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

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

namespace Cloudscape {

  CLAPI CLEngine* CreateEngine()
  {
    return new Engine();
  }

  CLAPI void DestroyEngine(CLEngine* engine)
  {
    delete engine;
  }

}