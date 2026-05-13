#pragma once
#include <event/Event.h>
#include <core/Common.h>

namespace engine {
    class KeyPressedEvent: public Event {
    public:
        explicit KeyPressedEvent(const ui32 keyCode): m_keyCode(keyCode) {}

        ui32 GetKeyCode() const {return m_keyCode;}

        EventType GetType() const override { return GetStaticType(); }

        static EventType GetStaticType() {
            return EventType::KeyPressed;
        }
    private:
        ui32 m_keyCode;
    };

}


