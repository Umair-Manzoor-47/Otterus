#pragma once
#include <event/Event.h>

namespace otterus::windowing::event
{
    class MouseButtonReleasedEvent : public Event
    {
    public:
        explicit MouseButtonReleasedEvent(int button)
            : m_button(button) {}

        int GetButton() const { return m_button; }

        EventType GetType() const override { return GetStaticType(); }

        static EventType GetStaticType() {
            return EventType::MouseButtonReleased;
        }

    private:
        int m_button;
    };
    
}

