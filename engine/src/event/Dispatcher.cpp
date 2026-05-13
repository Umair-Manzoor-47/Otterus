#include <event/Dispatcher.h>

engine::Dispatcher::SubscriberID engine::Dispatcher::Subscribe(
    EventType type,
    Callback callback)
{
    SubscriberID id = m_nextID++;

    m_listeners[type].emplace_back(id, std::move(callback));

    return id;
}

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