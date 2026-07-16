#pragma once
#include <functional>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <event/Event.h>

namespace otterus::windowing::event {

    class Dispatcher {
    public:
        using SubscriberID = unsigned int;

        template<typename T>
        SubscriberID Subscribe(std::function<void(T&)> callback);

        void Dispatch(Event& event);
        void Unsubscribe(EventType type, SubscriberID id);

    private:
        using Callback = std::function<void(Event&)>;
        using Listener = std::pair<SubscriberID, Callback>;
        using ListenerList = std::vector<Listener>;

        std::unordered_map<EventType, ListenerList> m_listeners;
        SubscriberID m_nextID = 0;
    };

}

#include <event/Dispatcher.inl>
