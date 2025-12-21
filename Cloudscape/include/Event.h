#pragma once

#include "Core.h"
#include <functional>

namespace Cloudscape {

	enum class EventType
	{
		None = 0,
		KeyPressed, KeyReleased,
		MouseMoved, MouseButtonPressed, MouseButtonReleased,
		WindowResize, WindowClose
	};

#define EVENT_CLASS_TYPE(type) \
  static EventType GetStaticType() { return EventType::type; } \
  virtual EventType GetEventType() const override { return GetStaticType(); } \
  virtual const char* GetName() const override { return #type; }

	class CLAPI Event
	{
	public:
		bool handled = false;

		virtual ~Event() = default;
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
	};

}

