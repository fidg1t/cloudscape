#pragma once

#include "CLSystem.h"
#include "CLLayer.h"
#include "Event.h"

namespace Cloudscape {

  class CLAPI EventSystem : public CLSystem
  {
  public:
    explicit EventSystem(std::vector<std::unique_ptr<CLLayer>>& layers);
    ~EventSystem() = default;

    void Update(float dt) override;

    void Push(std::unique_ptr<Event> event);

  private:
    std::vector<std::unique_ptr<Event>> m_eventQueue;
    std::vector<std::unique_ptr<CLLayer>>& m_engineLayers;
  };

}