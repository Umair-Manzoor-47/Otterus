#pragma once

namespace engine {
	class KeyReleasedEvent: public Event
	{
	public:
		explicit KeyReleasedEvent(const int keyCode): m_keyCode(keyCode) {}

		int GetKeyCode() const { return m_keyCode; }

		EventType GetType() const override { return GetStaticType(); }

		static EventType GetStaticType() { 
			return EventType::KeyReleased; 
	}
	private:
		int m_keyCode;
    
	};
}