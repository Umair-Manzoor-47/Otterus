#pragma once
#include <event/Event.h>

namespace otterus::windowing::event {
	class WindowCloseEvent : public Event {
	public:
		EventType GetType() const override { return GetStaticType(); }
		static EventType GetStaticType() { return EventType::WindowClose; }
	};

}
