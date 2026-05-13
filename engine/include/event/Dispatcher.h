#pragma once
#include <functional>
#include <core/Common.h>
#include <event/Event.h>
#include <algorithm>
namespace engine{
class Dispatcher
{

public:
    using SubscriberID = ui32;
    SubscriberID Subscribe(EventType type, std::function<void(Event&)> callback);
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
