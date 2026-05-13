#pragma once
#include <event/Dispatcher.h>

namespace engine {

    template<typename T>
    Dispatcher::SubscriberID Dispatcher::Subscribe(std::function<void(T&)> callback)
    {
        EventType type = T::GetStaticType();
        SubscriberID id = m_nextID++;

        m_listeners[type].emplace_back(id, [callback](Event& e) {
            callback(static_cast<T&>(e));
        });

        return id;
    }

}