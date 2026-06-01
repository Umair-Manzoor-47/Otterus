#pragma once
#include <event/Event.h>
namespace engine{
	class MouseButtonPressedEvent: public Event
	{
	public:
    	MouseButtonPressedEvent(const int button): m_button(button) {};
        int GetButton() const { return m_button; };
	    EventType GetType() const override { return GetStaticType(); }

    	static EventType GetStaticType() {
        	return EventType::MouseButtonPressed;
    	}	
	private:
		int m_button;
	};

}
