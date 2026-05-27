//
// Created by Umair Manzoor on 5/26/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#pragma once
#include <string>

namespace editor {
    class Panel {
    public:
        explicit Panel(const std::string& title) : m_title(title) {}
        virtual ~Panel() = default;
        virtual void OnRender() = 0;

    protected:
        std::string m_title;
    };
}
