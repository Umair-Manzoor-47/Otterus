#pragma once

namespace engine {

class MouseMovedEvent : public Event
{
public:
    MouseMovedEvent(double x, double y)
        : m_x(x), m_y(y) {}

    double GetX() const { return m_x; }
    double GetY() const { return m_y; }

    std::pair<double, double> GetPosition() const { return { m_x, m_y }; }

    EventType GetType() const override { return GetStaticType(); }

    static EventType GetStaticType() {
        return EventType::MouseMoved;
    }

private:
    double m_x, m_y;
};

}
