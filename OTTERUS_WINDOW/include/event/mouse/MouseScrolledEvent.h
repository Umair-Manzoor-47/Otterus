#pragma once

namespace otterus::windowing::event {

class MouseScrolledEvent : public Event
{
public:
    MouseScrolledEvent(double xOffset, double yOffset)
        : m_xOffset(xOffset), m_yOffset(yOffset) {}

    double GetXOffset() const { return m_xOffset; }
    double GetYOffset() const { return m_yOffset; }

    std::pair<double, double> GetOffset() const { return { m_xOffset, m_yOffset }; }

    EventType GetType() const override { return GetStaticType(); }

    static EventType GetStaticType() {
        return EventType::MouseScrolled;
    }

private:
    double m_xOffset, m_yOffset;
};

}