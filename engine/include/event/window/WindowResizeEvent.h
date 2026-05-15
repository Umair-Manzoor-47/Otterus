#pragma once

namespace engine{
	class WindowResizeEvent: public Event
	{
	public:
   		explicit WindowResizeEvent(const int width, const int height): m_width(width), m_height(height){};
		int GetWidth() const{return m_width;}
		int GetHeight() const{return m_height;}
		
		EventType GetType() const override { return GetStaticType(); }
		static EventType GetStaticType() { return EventType::WindowResize; }
	private:
		int m_width;
		int m_height;
	};

}
