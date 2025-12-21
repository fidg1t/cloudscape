#include "EventSystem.h"
#include "CLEngine.h"

namespace Cloudscape {

	EventSystem::EventSystem(std::vector<std::unique_ptr<CLLayer>>& layers)
		: m_engineLayers(layers)
	{

	}

	void EventSystem::Update(float dt)
	{
		for (auto& event : m_eventQueue)
		{
			for (auto& layer : m_engineLayers )
			{
				layer->OnEvent(*event);
				if (event->handled)
					break;
			}
		}
		m_eventQueue.clear();
	}

	void EventSystem::Push(std::unique_ptr<Event> event)
	{
		m_eventQueue.emplace_back(std::move(event));
	}

}