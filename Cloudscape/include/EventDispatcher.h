#pragma once

#include "Event.h"
#include <functional>

namespace Cloudscape {

	class EventDispatcher
	{
		template <typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_event(event) { }

		template <typename T>
		bool Dispatch(const EventFn<T>& func)
		{
			if (m_event.GetEventType() == T::GetStaticType() && !m_event.handled)
			{
				m_event.handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}
	private:
		Event& m_event;
	};

}
