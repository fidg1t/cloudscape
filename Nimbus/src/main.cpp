#include "CLEngine.h"
#include "CLSystem.h"
#include <iostream>

namespace Cloudscape {

  class FakeSystem : public CLSystem
  {
  public:
    void Init() override { std::cout << "FakeSystem Init\n"; }
    void Load() override { std::cout << "FakeSystem Load\n"; }
    void Update(float dt) override { std::cout << "FakeSystem Updating...\n"; }
    void Draw() override { std::cout << "FakeSystem Drawing...\n"; }
    void Unload() override { std::cout << "FakeSystem Unload\n"; }
    void Exit() override { std::cout << "FakeSystem Exit\n";  }
  };

}

int main()
{
  Cloudscape::CLEngine* engine = Cloudscape::CreateEngine();
  std::unique_ptr<Cloudscape::FakeSystem> system = std::make_unique<Cloudscape::FakeSystem>();

  bool isRunning = true;
  int testCount = 0;
  float dt = 0.0f;

  engine->AddSystem(std::move(system));

  engine->Init();
  engine->Load();

  while (isRunning)
  {
    engine->Update(dt);
    engine->Draw();

    if (testCount++ == 200)
    {
      isRunning = false;
    }
  }

  engine->Unload();
  engine->Exit();

  Cloudscape::DestroyEngine(engine);

  return 0;
}