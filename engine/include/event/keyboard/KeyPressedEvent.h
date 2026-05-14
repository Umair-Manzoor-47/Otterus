#pragma once
#include <event/Event.h>
#include <core/Common.h>

namespace engine {
    class KeyPressedEvent: public Event {
    public:
        explicit KeyPressedEvent(const int keyCode): m_keyCode(keyCode) {}

        int GetKeyCode() const {return m_keyCode;}

        EventType GetType() const override { return GetStaticType(); }

        static EventType GetStaticType() {
            return EventType::KeyPressed;
        }
    private:
        int m_keyCode;
    };

}


