#pragma once
#include <core/Common.h>

namespace engine {

	class Event {
	public:
		virtual ~Event() = default;
		virtual EventType GetType() const = 0;
		// Subclasses must also implement:
		// static EventType GetStaticType()
		bool Handled { false };
	};

}
