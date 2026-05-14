#pragma once
#include <event/Event.h>
#include <core/Common.h>
namespace engine {
	class WindowCloseEvent : public Event {
	public:
		EventType GetType() const override { return GetStaticType(); }
		static EventType GetStaticType() { return EventType::WindowClose; }
	};

}
