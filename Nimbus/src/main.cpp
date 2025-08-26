#include "CLEngine.h"
#include <iostream>

int main()
{
  Cloudscape::CLEngine* engine = Cloudscape::CreateEngine();

  engine->Run();

  Cloudscape::DestroyEngine(engine);

  return 0;
}