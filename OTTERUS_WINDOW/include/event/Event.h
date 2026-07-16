#pragma once

namespace otterus::windowing::event {

	enum class EventType
	{
		None = 0,
		// Window
		WindowClose, WindowResize,
		// Keyboard
		KeyPressed, KeyReleased,
		// Mouse
		MouseMoved, MouseButtonPressed, MouseButtonReleased, MouseScrolled
	};

	class Event {
	public:
		virtual ~Event() = default;
		virtual EventType GetType() const = 0;
		// Subclasses must also implement:
		// static EventType GetStaticType()
		bool Handled { false };
	};

}
