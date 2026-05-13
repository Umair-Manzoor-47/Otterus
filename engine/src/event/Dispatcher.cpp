#include <event/Dispatcher.h>


void engine::Dispatcher::Dispatch(Event& event)
{
    auto it = m_listeners.find(event.GetType());

    if (it == m_listeners.end())
        return;

    auto& listeners = it->second;

    for (auto& [id, callback] : listeners)
    {
        if (event.Handled) break;
        if (callback)
        {
            callback(event);
        }
    }
}

void engine::Dispatcher::Unsubscribe(EventType type, SubscriberID id)
{
    auto it = m_listeners.find(type);

    if (it == m_listeners.end())
        return;

    auto& listeners = it->second;

    listeners.erase(
        std::remove_if(
            listeners.begin(),
            listeners.end(),
            [id](const Listener& listener)
            {
                return listener.first == id;
            }),
        listeners.end());
    
    if (listeners.empty())
    {
        m_listeners.erase(it);
    }
}