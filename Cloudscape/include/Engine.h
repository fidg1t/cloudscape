#pragma once

#ifdef ENGINE_EXPORTS
  #define CLAPI __declspec(dllexport)
#else
  #define CLAPI __declspec(dllimport)
#endif

namespace Cloudscape {

  class CLAPI Engine
  {
  public:
    void Hello();
  };

}